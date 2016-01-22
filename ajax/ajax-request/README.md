<link href="public/css/application.css" rel="stylesheet" type="text/css">
<h1>XHR (AJAX) Request</h1>

<p>A description of how a typical XHR (AJAX) request works including the various systems involved, what they do, and how they interact. AJAX is an acronym for Asynchronous JavaScript and XML.</p>

<p>Technologies: AJAX, JavaScript, jQuery, JSON, Ruby, Sinatra.</p>

<h3>From a Users perspective, explain an XHR (AJAX) request:</h3>

<p>When a User clicks or scrolls on a webpage, an XHR request prevents the whole web page from reloading. Instead only part of the web page is updated asynchronously. This enables other scripts to run at the same time, without the web page slowing down due to having to reload the entire page.</p> 

<p>Examples of applications using XHR (AJAX) requests include the vote buttons on Stack Overflow, asynchronous scrolling and posting on Facebook, asynchronous email on Gmail, and more!

<h3>From a coders perspective, explain an XHR (AJAX) request:</h3>

<p>In a nutshell, an XHR (AJAX) request stops the web page from making a call to the server (without an XHR request the call would go to the server, causing the entire web page to be reloaded). The XHR request is handled - either data is sent to the controller to be stored in the database, or data is retrieved by the controller from the database to render on the web page. Finally, part of the web page is updated asynchronously.</p>

<p>Flow of an XHR (AJAX) request:</p>
<ol>
	<li>A web page has a function bound to an event. The event could be when a User clicks a button, triggering the event.</li>  
	<li>A User clicks a button on a form, triggering an event. Normally the event goes to the server and the web page gets refreshed. However, with an XHR request, an event handler that heard the click prevents the request from going to the server and the page is prevented from refreshing.</li>
	<li>The XHR request directs to the controller, carrying the data from the form. A 'GET' route retrieves data from the database, and a 'POST' route makes changes (creates, updates, deletes) to data in the database.</li>
	<li>Depending on the request to a 'GET' or 'POST' route, the response is sent back from the controller to the XHR request. The web page then gets updated asynchronously.</li>
</ol>

<p>Anatomy of an XHR (AJAX) request. In this short example, a User clicks on a submit button on a web page to see all of entries stored in the database. The web page does not refresh, and all of the entries are shown on the page when the User clicks submit.</p>
<pre><code>
<i>application.js</i>
//execute after the page has loaded.
$(document).ready(function(){
  //for the form element, handle the 'submit' event in this way.
  $("form").submit(function(event){
    //prevent the page from refreshing when the 'submit' event is triggered.
    event.preventDefault();
    $.ajax({
      //the 'GET' route in the controller retrieves data from the database, 'POST' route makes changes to the data in the database.
      type: 'GET',
      //the URL for which the request is sent. Here it is sent to the route in the controller called '/entries'.
      url: '/entries',
      //if we were making a 'POST' request, here we would serialize form data to a query string. Omit if making a 'GET' request.
      data: $(this).serialize,
      //will convert the string to an array
      dataType: 'json' 
    }).done(function(response){
      //the response comes back from the database and the server, and is asynchonously rendered on the web page in the span tag with the id 'all-entries'. 
      ("span #all-entries").text(response)
    });
  });
});

<i>controller/index.rb</i>
get '/entries' do
  @entries = Entry.all
  if request.xhr?
    @entries.to_json
  else
    erb :'entries/index'
  end
end 

<i>entries/index.html.erb</i>
<div>
  <span id="all-entries">
  </span>
</div>
</code></pre> 

<p>A typical XHR get request:</p>
<img src="ajax-request.JPG" alt="XHR Request" height="45%" width="60%">

