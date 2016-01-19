class SessionsController < ApplicationController

  def new
  end

  def create
    p @user = User.find_by_email(params[:sessions][:email])
      if @user && @user.authenticate(params[:sessions][:password])
        session[:user_id] = @user.id
        if current_user.admin?
          redirect_to products_path
        else
          redirect_to root_path
        end    
      else
        @error = "Your password or email was incorrect"
        redirect_to new_session_path
      end
  end

  def destroy
    session[:user_id] = nil
    redirect_to root_path
  end
end
