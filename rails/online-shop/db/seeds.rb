# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)

n = 1
# 1 through 10 will be admin users
until n == 11
  User.create(first_name: n.to_s, last_name: n.to_s, email: n.to_s, password: n.to_s, admin?: true)
  n += 1
end

# 11 through 20 will be regular users
until n == 21
  User.create(first_name: n.to_s, last_name: n.to_s, email: n.to_s, password: n.to_s, admin?: false)
  n += 1
end

Product.create(title: "Vintage Chalet", description: "Skiing winter wonderland", image_url: "http://www.afficheprints.com/ebay/TX182THM.jpg", price: 10, quantity: 20)
Product.create(title: "Winter Sun", description: "Holiday warmth", image_url: "http://static.freevector365.com/uploads/posts/2013-11/1383573576_eps13333.jpg", price: 15, quantity: 25)
Product.create(title: "Winter Magic", description: "Fairy glitter is the best", image_url: "http://www.sharynalicemurray.com/wp-content/uploads/2013/06/winter-solstice-celebration.jpg", price: 5, quantity: 5)
Product.create(title: "Alaskan Holiday", description: "Far far away fun", image_url: "http://www.legion.org/documents/legion/posters/758.jpg", price: 16, quantity: 10)
Product.create(title: "French Vacation", description: "Oui oui", image_url: "https://harrisonchasedotcom.files.wordpress.com/2012/11/winter-poster-01web1.jpg", price: 8, quantity: 6)

Product.create(title: "Downhill", description: "look at me", image_url: "http://www.idesirevintageposters.com/images/Winter_Bewitches.jpg", price: 12, quantity: 5)

Product.create(title: "Ski Aspen", description: "Love it", image_url: "http://viintage.com/wp-content/uploads/public-domain-images-the-first-winter-olympics-1924.jpg", price: 18, quantity: 5)

Product.create(title: "Penguin", description: "Who doesn't love a penguin skiing", image_url: "https://vepca.files.wordpress.com/2011/01/viii-jeux-olympiques-dhiver-flag.jpg", price: 22, quantity: 6)
