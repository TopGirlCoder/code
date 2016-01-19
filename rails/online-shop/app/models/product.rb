class Product < ActiveRecord::Base
  validates :title, :description, :image_url, :price, :quantity, presence: true
  validates :quantity, numericality: {only_integer: true}
  validates :price, numericality: {only_decimal: true} 
  validates :price, numericality: {greater_than_or_equal_to: 0.01}
  validates :image_url, allow_blank: true, format: {with: %r{\.(gif|jpg|png)\Z}i, message: "Must be a URL for GIF, JPG, or PNG image."}

  has_many :line_products

  before_destroy :ensure_not_referenced_by_any_line_product

  private
    def ensure_not_referenced_by_any_line_product
    	if line_products.empty?
    		return true
    	else
    		errors.add(base, 'Line Products present')
    		return false
    	end
    end			
end
