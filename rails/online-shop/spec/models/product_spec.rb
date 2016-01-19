require 'rails_helper'

RSpec.describe Product, type: :model do

  let(:good_product) {Product.new(title: 'Title', description: 'desc', image_url: 'test.gif', price: 50, quantity: 50)}
  let(:product_no_title) {Product.new(description: 'desc', image_url: 'test.gif', price: 50, quantity: 50)}
  let(:product_no_desc) {Product.new(title: 'Title', image_url: 'test.gif', price: 50, quantity: 50)}
  let(:product_no_price) {Product.new(title: 'Title', description: 'desc', image_url: 'test.gif', quantity: 50)}
  let(:product_no_qty) {Product.new(title: 'Title', image_url: 'test.gif', description: 'desc', price: 50)}
  let(:product_image_format) {Product.new(title: 'Title', description: 'desc', image_url: 'test123', price: 50, quantity: 50)}
  let(:product_with_noninteger_price) {Product.new(title: 'Title', description: 'desc', price: "uoi", quantity: 50)}
  let(:product_with_noninteger_qty) {Product.new(title: 'Title', description: 'desc', price: 55, quantity: "poi")}

  describe 'validations' do
    context 'will raise an error' do
      it 'when the title is missing' do
        product_no_title.save
        expect(product_no_title.errors[:title]).to include("can't be blank")
      end
      it 'when the description is missing' do
        product_no_desc.save
        expect(product_no_desc.errors[:description]).to include("can't be blank")
      end
      it 'when the price is missing' do
        product_no_price.save
        expect(product_no_price.errors[:price]).to include("can't be blank")
      end
      it 'when the qty is missing' do
        product_no_qty.save
        expect(product_no_qty.errors[:quantity]).to include("can't be blank")
      end
      it 'when the image is in the wrong format' do
        product_image_format.save
        expect(product_image_format.errors[:image_url]).to include("Must be a URL for GIF, JPG, or PNG image.")
      end
      it 'when the price is not an integer' do
        product_with_noninteger_price.save
        expect(product_with_noninteger_price.errors[:price]).to include("is not a number")
      end
      it 'when the quantity is not an integer' do
        product_with_noninteger_qty.save
        expect(product_with_noninteger_qty.errors[:quantity]).to include("is not a number")
      end
    end
    context 'it will successfully save when' do
      it 'saves when all fields are present' do
        expect{good_product.save}.to change{Product.count}.by(1)
      end
    end
  end
end
