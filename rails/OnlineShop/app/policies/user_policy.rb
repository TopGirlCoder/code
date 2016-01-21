class UserPolicy < ApplicationPolicy

  def edit?
    user.admin?
  end

  def destroy?
    user.admin?
  end

end
