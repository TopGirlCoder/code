FactoryGirl.define do
  factory :admin, class: User do
    first_name {"admin"}
    last_name {"admin"}
    email {"admin"}
    password {"admin"}
    admin? {true}
  end

  factory :user do
    first_name {Faker::Name.first_name}
    last_name {Faker::Name.last_name}
    email {Faker::Internet.email}
    password {"password"}
    admin? {false}
  end
end