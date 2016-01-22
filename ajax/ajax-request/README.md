<link href="public/css/application.css" rel="stylesheet" type="text/css">
<h1>XHR (AJAX) Request</h1>

<p>A description of how a typical XHR (AJAX) request works including the various systems involved, what they do, and how they interact. AJAX is an acronym for Asynchronous JavaScript and XML.</p>

<p>Technologies: AJAX, JavaScript, jQuery, JSON, Ruby, Sinatra.</p>

<h3>From a Users perspective, explain an XHR (AJAX) request:</h3>

<p>When a User clicks or scrolls on a webpage, an XHR request prevents the whole web page from reloading. Instead only part of the web page is updated asynchronously. This enables other scripts to run at the same time, without the web page slowing down due to having to reload the entire page.</p> 

<p>Examples of applications using XHR (AJAX) requests include the vote buttons on Stack Overflow, asynchronous scrolling and posting on Facebook, asynchronous email on Gmail, and more!

<h3>From a coders perspective, explain an XHR (AJAX) request:</h3>

<p>In a nutshell, an XHR (AJAX) request stops the web page from making a call to the server (without an XHR request the call would go to the server, causing the entire web page to be reloaded). The XHR request is handled asynchronously - either data is sent to the controller to be stored in the database, or data is retrieved by the controller from the database to render on the web page. Finally, if data is being retrieved from the database, then the data gets rendered on the web page.</p>

<h3>Flow of an XHR (AJAX) request:</h3>

<p>Web page -> JS (XHR request) -> Controller -> Database <br>
Web page <- JS (response) <- Controller <- Database </p>

<ol>
	<li>A web page has a function bound to an event. The event could be when a User clicks a button, triggering the event.</li> 
	<li>A User clicks a button on a form, triggering an event. Normally the event goes to the server and the web page gets refreshed. However, with an XHR request, an event handler that heard the click prevents the request from going to the server and the page is prevented from refreshing.</li>
	<li>The XHR request directs to the controller, carrying the data from the form. A 'GET' route retrieves data from the database, and a 'POST' route makes changes (creates, updates, deletes) to data in the database.</li>
	<li>Depending on the request to a 'GET' or 'POST' route, the response is sent back from the controller to the XHR request. The web page then gets updated asynchronously.</li>
</ol>

<h3>Anatomy of an XHR (AJAX) request.</h3> 

<p>In this short example, a User clicks a submit button on a web page to see all of entries stored in the database. The entries are displayed on the web page asynchronously.</p>

<p>application.js</p>
<pre><code>
$(document).ready(function(){
  $("form").submit(function(event){
    event.preventDefault();
    $.ajax({
      type: 'GET',
      url: '/entries',
      data: $(this).serialize,  
      dataType: 'json' 
    }).done(function(response){
      ("span #all-entries").text(response)
    });
  });
});
</code></pre> 

<p>controller/index.rb</p>
<pre><code>
get '/entries' do
  @entries = Entry.all
  if request.xhr?
    @entries.to_json
  else
    erb :'entries/index'
  end
end 
</code></pre> 

<h3>Detailed explanation of an XHR (AJAX) request.</h3>

<p>In the application.js file</p>

<p>Execute when the web page has loaded:</p>

<pre><code>
  $(document).ready(function(){
</code></pre>

<p>For the form element, handle the 'submit' event in this way:</p>
<pre><code>
  $("form").submit(function(event){
</code></pre>

<p>Prevent the page from refreshing when the 'submit' event is triggered:</p>
<pre><code>
  event.preventDefault();
</code></pre>

<p>AJAX call directs to a route with the data from the form:</p>
<pre><code>
  $.ajax({
</code></pre>

<p>The 'GET' route in the controller retrieves data from the database, 'POST' route makes changes to the data in the database:</p>
<pre><code>
  type: 'GET',
</code></pre>

<p>The URL for which the request is sent. Here it is sent to the route in the controller called '/entries':</p>
<pre><code>
  url: '/entries',
</code></pre>

<p>If we were making a 'POST' request, here we would serialize form data to a query string (OMIT if making a 'GET' request. It should be omitted in this example because we're making a 'GET' request):</p>
<pre><code>
  data: $(this).serialize,
</code></pre>

<p>This will convert a string into an array with key value pairs:</p>
<pre><code>
  dataType: 'json' 
</code></pre>  

<p>The response comes back from the database and the server to the .done method:</p>
<pre><code>
  }).done(function(response){
</code></pre> 

<p>The response is asynchonously rendered on the web page in the span tag with the id 'all-entries'.</p>
<pre><code>
  ("span #all-entries").text(response)
</code></pre> 
      
<p>A typical XHR get request:</p>
<img src="ajax-request.JPG" alt="XHR Request" height="45%" width="60%">

