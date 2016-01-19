require 'rails_helper'

RSpec.describe WelcomeController, type: :controller do

	describe "go to welcome page" do
		context 'user is logged in' do
			let!(:admin){FactoryGirl.create(:admin)}
			before do
			    session[:user_id] = admin.id
			end
			it "redirects to products page" do
			    get :index
			    expect(response).to redirect_to(products_path)
			end
		end
		context 'user is not logged in' do
			it "redirects to index page" do
			    get :index
			    expect(response).to have_rendered('index')
			end
		end
    end
end
