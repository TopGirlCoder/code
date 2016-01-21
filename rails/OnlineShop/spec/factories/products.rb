FactoryGirl.define do
  factory :product do
    title {"poster"}
    description {"something nice to buy"}
    image_url {"test.gif"}
    price {1.11}
    quantity{3}
  end
end