require 'rails_helper'
require 'factory_girl'
require 'selenium-webdriver'
require 'capybara/rspec'

RSpec.feature "Users", type: :feature do
  let!(:user) {FactoryGirl.create :user}
  let! (:admin) {FactoryGirl.create :admin}

  describe "landing page", js: true do
    before(:each) do
      visit root_path
    end

    describe 'registration process' do
      it 'can open registration form' do
        expect(page).to have_content('Register')
        click_on "Register"
        fill_in 'user[first_name]', with: 'nathan'
        fill_in 'user[last_name]', with: 'park'
        fill_in 'user[email]', with: 'n@gmail.com'
        fill_in 'user[password]', with: 'test'
        click_on 'Create User'
        expect(page).to have_content('nathan')
      end
    end

    describe 'can log in and log out' do
      it 'can click and view Login field' do
        expect(page).to have_content('Email')
        expect(page).to have_content('Password')
      end

      it 'can login user' do
        fill_in 'sessions[email]', with: admin.email
        fill_in 'sessions[password]', with: admin.password
        click_on 'Log In'
        expect(page).to have_content('Product List')
        expect(page).to have_content('Log Out')
      end
    end

    describe 'tests access_level functionality' do
      let!(:product) {FactoryGirl.create(:product)}
      before do
        fill_in 'sessions[email]', with: admin.email
        fill_in 'sessions[password]', with: admin.password
        click_on 'Log In'
      end

      context 'admins have access to full funcitonality' do
        it 'allows admins to see inventory' do
          expect(page).to have_content('Add Products')
          expect(page).to have_content('User List')
        end

        it 'is allowed to additems' do
          click_on 'Add Product'
          fill_in 'product[title]', with: 'test'
          fill_in 'product[description]', with: 'data'
          fill_in 'product[image_url]', with: 'test.gif'
          fill_in 'product[price]', with: 1
          fill_in 'product[quantity]', with: 2
          click_on 'Create Product'
          expect(page).to have_content('test')
          expect(page).to have_content('data')
          expect(page).to have_content('Edit')
          expect(page).to have_content('Delete')
          click_on 'Product List'
        end

        it 'is allowed to edit product' do
          click_on 'poster'
          expect(page).to have_content('poster')
          expect(page).to have_content('Edit')
          expect(page).to have_content('Delete')
          click_on 'Edit'
          fill_in 'product[title]', with: 'changed'
          fill_in 'product[description]', with: '12345'
          click_on 'Update Product'
          expect(page).to have_content('changed')
          expect(page).to have_content('12345')
        end

        it 'should delete a product' do
          click_on 'Delete'
          expect(page).to have_content('Product List')
          expect(page).to have_no_content('poster')
        end
      end
    end

  end
end