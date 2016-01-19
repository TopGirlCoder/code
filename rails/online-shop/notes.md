shows the title of a line_product in a cart:
@line_product = LineProduct.find(...)
@line_product.product.title 


shows how many products a cart has:
@cart = Cart.find(...)
@cart.line_products.count 

$(document).on 'ready page:load', ->
$(document).on 'click', '#register-button', ->
  $('#register-form').show();
  $('#login-form').hide();

**********************
_line_products.html.erb

<caption>Your Cart</caption>
<thead>
  <tr>
    <th class='small-2 '>Title</th>
    <th class='small-1 '>Image</th>
    <th class='small-1 '>Quantity & Price</th>

  </tr>
</thead>
<tbody>
  <% @cart.line_products.each do |item| %>
    <tr>
      <td><%= item.product.title %></td>
      <td><%= image_tag(item.product.image_url) %></td>
      <td><%= item.quantity %> &times;
      	<%= number_to_currency(item.product.price) %></td>
    </tr>
  <% end %> 

********************
  show.html.erb
<div>
  <% if notice %>
    <p id="notice"> <%= notice %> </p>
  <% end %>

  <table>
    <!-- _line_products -->
    <%= render (@cart.line_products)%>
    <tr>
      <td></td>
      <td></td>
      <td>Total: <%= number_to_currency(@cart.total_price) %></td>
    </tr>    
    </tbody>
  </table>

  <%= button_to 'Empty Cart', @cart, method: :delete, data: { confirm: 'Are you sure?' } %> 
</div>

************
products/index.html.erb


<table>
  <caption>Product List</caption>
  <thead>
    <tr>
      <th class='small-2 '>Title</th>
      <th class='small-4 '>Description</th>
      <th class='small-1 '>Image Url</th>
      <th class='small-1 '>Price</th>
      <th class='small-1 '>Quantity</th>
      <% if current_user.admin? %>
        <th class='small-1 '>Actions</th>
      <% end %>
    </tr>
  </thead>
  <tbody>
    <% @products.each do |product| %>
      <tr>
        <td><%= link_to product.title, product_path(product) %></td>
        <td><%= product.description %></td>
        <td><%= image_tag(product.image_url) %></td>
        <td><%= number_to_currency(product.price) %></td>
        <td><%= product.quantity %></td>
        <% if current_user.admin?%>
          <td><%= link_to 'Edit', edit_product_path(product) %> <%= link_to 'Delete', product_path(product), method: :delete %></td>
        <%end %>
      </tr>
    <% end %>
  </tbody>
</table>