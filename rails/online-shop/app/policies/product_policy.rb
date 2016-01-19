class ProductPolicy < ApplicationPolicy
  attr_reader :user, :product

  def initialize(user, product)
    @user = user
    @product = product
  end

  def show?
    scope.where(:id => product.id).exists?
  end

  def create?
    @user.admin?
  end

  def new?
    create?
  end

  def update?
    @user.admin?
  end

  def edit?
    update?
  end

  def destroy?
    @user.admin?
  end

end
