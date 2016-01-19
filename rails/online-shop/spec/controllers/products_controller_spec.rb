require 'rails_helper'
require 'factory_girl'

RSpec.describe ProductsController, type: :controller do
  let!(:admin){FactoryGirl.create(:admin)}

  before do
    session[:user_id] = admin.id
    @all_products = 10.times.map do
      Product.create(title: 'hi', description: 'hihihi', image_url: 'test.gif', price: 1, quantity: 1)
    end
  end

    describe "get products" do
      it "assigns @products" do
        get :index
        expect(assigns[:products]).to match(@all_products)
      end

      it "renders the index template" do
        get :index
        expect(response.status).to eq 200
        expect(response).to have_rendered(:index)
      end
    end

    describe "GET new" do
      it "renders the new form template" do
        product = Product.new
        get :new
        expect(response).to have_rendered("products/new")
      end
    end

   describe "GET edit" do
      let(:edit_product) do
        Product.find_by_title('hi')
      end

      it "renders the edit form template with selected item" do
        get :edit, id: edit_product
        expect(response).to have_rendered("edit")
      end

      it 'should find a product by id' do
        expect(edit_product.is_a?(Object)).to be true
      end

    end

    describe 'CREATE a new product' do
      context 'when given valid params' do
        let :product_params do
          {title: 'my first product', description: 'I have a product', image_url: 'test.gif', price: 100, quantity: 1}
        end
        it 'should create the product and redirect to the product index page' do
          expect{
            post :create, product: product_params
          }.to change{ Product.count }.by(1)
        end
      end
      context 'when given invalid params' do
        let :product_params do
          {description: 'I have a product'}
        end
        it 'should not create the post and re-render the new page' do
          expect{
            post :create, product: product_params
          }.to_not change{ Product.count }
        end
      end
    end

    describe "GET show" do
      it "renders the show page with selected item" do
        Product.create(title: "puppies", description: "refreshing", image_url: 'test.gif', price: 25, quantity: 12)
        product = Product.find_by(title: "puppies")
        get :show, id: product
        expect(response).to have_rendered("show")
      end
    end
    describe 'update product' do
      context 'updates a given product, with valid params' do
        let(:update_product) do
          Product.last
        end

        let(:updates) do
          { :title => 'new title', :description => 'new content' }
        end

        before(:each) do
          put :update, :id => update_product.id, :product => updates
          update_product.reload
        end

        it { expect(response).to redirect_to(update_product) }
        it { expect(update_product.title).to eql updates[:title] }
        it { expect(update_product.description).to eql updates[:description] }

        it 'should find a product' do
          expect( Product.find(update_product.id) ).to eq(update_product)
        end

        it 'should update the product' do
          expect{ put :update, product: {title: "12345"} }

          expect{update_product.update(title: 'changed', description: 'different')}.to change{ update_product.title && update_product.description }
        end
      end
      context 'redirects to edit if update fails' do
        let (:update_product) do
          Product.last
        end

        let (:updates) do
          { title: 123, price: "123", quantity: "000" }
        end

        before(:each) do
          put :update, :id => update_product.id, :product => updates
          update_product.reload
        end

        it { expect(response).to have_rendered('edit') }

      end
    end
    describe 'DELETE product' do
      it 'successfully deletes an item' do
        product = Product.create(title: "puppies", description: "refreshing", image_url: 'test.gif', price: 25, quantity: 12)
        expect{ delete :destroy, id: product.id }.to change{ Product.count }.by(-1)
      end
    end
end
