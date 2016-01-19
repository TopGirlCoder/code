class CombineItemsInCart < ActiveRecord::Migration
  
  def up
    # When multiple line_products that are the same products exist in a cart, replace with one product
  	Cart.all.each do |cart|
  	  # Count the number of each product in the cart
  	  sums = cart.line_products.group(:product_id).sum(:quantity)
  	  # checks for multiples, deletes multiples
  	  sums.each do |product_id, quantity|
  	    if quantity > 1
  		  #remove the product
  		  cart.line_products.where(product_id: product_id).delete_all
  		  # replace with a single product
  		  product = cart.line_products.build(product_id: product_id)
  		  product.quantity = quantity
  		  product.save!
  		end
  	  end
  	end			
  end

  # makes the up method reversible
  def down
  	# products greater than 1 will be listed as multiple products
  	LineProduct.where("quantity>1").each do |line_product|
  	  # add products
  	  line_product.quantity.times do 
  	  	LineProduct.create(cart_id: line_product.cart_id, product_id: line_product.product_id, quantity: 1)
  	  end
  	  # remove original line_product
  	  line_product.destroy
  	end  	
  end
end
