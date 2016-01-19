class UsersController < ApplicationController

  def index
    @users = User.order(:last_name)
  end

  def new
    @user = User.new
  end

  def edit
    @user = User.find(params[:id])
  end

  def create
    @user = User.new(user_params)
    if @user.save
      if @user.id <= 10
        @user.update(admin?: true)
        @user.reload
        session[:user_id] = @user.id
      end
      @user.reload
      session[:user_id] = @user.id
      redirect_to @user
    else
      redirect_to new_user_path
    end
  end

  def show
    @user = User.find(params[:id])
  end

  def update
    @user = User.find(params[:id])
    if @user.update(user_params)
      redirect_to @user
    else
      render 'edit'
    end
  end

  def destroy
    @user = User.find(params[:id])
    if @user == current_user
      session[:user_id] = nil
      @user.destroy
      redirect_to root_path
    else
      @user.destroy
      redirect_to users_path
    end
  end

  private
  def user_params
    params.require(:user).permit(:first_name, :last_name, :email, :password, :admin?)
  end

end
