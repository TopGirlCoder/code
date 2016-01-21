require 'rails_helper'

RSpec.describe UsersController, type: :controller do

    let(:all_users) do
    	10.times.map do
		    User.create(first_name: 'test', last_name: 'test', email: 'test@gmail.com', password: 'password')
		end
	end

    describe "get users" do
      it "assigns all_users" do
        get :index
        expect(assigns[:users]).to match(all_users)
      end

      it "renders the index template" do
        get :index
        expect(response.status).to eq 200
        expect(response).to have_rendered(:index)
      end
    end

	describe 'get new users' do
		let(:new) { User.new }
		it 'should return a new user object' do
			get :new
			expect(response).to have_rendered('new')
		end
	end

    describe 'CREATE a new user' do
      context 'when given valid params' do
        let :user_params do
          {first_name: 'test', last_name: 'test', email: 'test@gmail.com', password: 'password'}
        end
        it 'should create the user and redirect to the user page' do
          expect{
            post :create, user: user_params
          }.to change{ User.count }.by(1)
        end
      end
      context 'when given admin params' do
      	let :admin_params do
          {id: 1, first_name: 'test', last_name: 'test', email: 'test@gmail.com', password: 'password'}
        end
        it 'should make the user an admin and redirect to the user page' do
          expect{
            post :create, user: admin_params
          }.to change{ User.count }.by(1)
        end
      end
      context 'when given invalid params' do
        let :user_params do
          {first_name: 'hello'}
        end
        it 'should not create the user and re-render the new user page' do
          expect{
            post :create, user: user_params
          }.to_not change{ User.count }
        end
      end
    end

    describe 'update users' do
		let!(:admin){FactoryGirl.create(:admin)}

    	context 'when given valid params' do 
    		let(:update_params) do
    			{first_name: 'test', last_name: 'test', email: 'test@gmail.com', password: admin.password}
    		end
		    it 'updates user when logged in' do
		    	put :update, id: admin.id, user: update_params 
		    	admin.reload
		    	expect(admin.first_name).to eq('test')
		    end
		end
	end

	describe 'edit users' do
		let(:edit_user) { User.create(first_name: 'test', last_name: 'test', email: 'test@gmail.com', password: 'password') }
		it 'should return a specific user' do
			get :edit, id: edit_user.id
			expect(response).to have_rendered('edit')
		end
	end

	describe 'show users' do
		let(:show_user) { User.create(first_name: 'test', last_name: 'test', email: 'test@gmail.com', password: 'password') }
		it 'should return a specific user' do
			get :show, id: show_user.id
			expect(response).to have_rendered('show')
		end
	end

	describe 'DELETE product' do
		let(:delete_user) { User.create(first_name: 'test', last_name: 'test', email: 'test@gmail.com', password: 'password') }
	    it 'successfully deletes an item' do
	        expect{ delete :destroy, id: delete_user.id }.to change{ User.count }.by(0)
	    end
    end

end
