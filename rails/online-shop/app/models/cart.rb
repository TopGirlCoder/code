class Cart < ActiveRecord::Base
	has_many :line_products, dependent: :destroy

	def add_product(product_id)
		current_product = line_products.find_by(product_id: product_id)
		if current_product
			current_product.quantity += 1
		else 
			current_product = line_products.build(product_id: product_id)
		end
		current_product
	end	

	def total_price
		line_products.to_a.sum { |product| product.total_price }
	end			


end
