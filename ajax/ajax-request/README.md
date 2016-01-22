<h1>XHR (AJAX) Request</h1>

<p>A description of how a typical XHR (AJAX) request works including the various systems involved, what they do, and how they interact. AJAX is an acronym for Asynchronous JavaScript and XML.</p>

<p>Technologies: AJAX, JavaScript, jQuery, JSON, Ruby, Sinatra.</p>

<h3>From a Users perspective, explain an XHR (AJAX) request:</h3>

<p>When a User clicks or scrolls on a webpage, an XHR request prevents the whole web page from reloading. Instead only part of the web page is updated asynchronously. This enables other scripts to run at the same time, without the web page slowing down due to having to reload the entire page.</p> 

<p>Examples of applications using XHR (AJAX) requests include the vote buttons on Stack Overflow, asynchronous scrolling and posting on Facebook, asynchronous email on Gmail, and more!

<h3>From a coders perspective, explain an XHR (AJAX) request:</h3>

<p>In a nutshell, an XHR (AJAX) request stops the web page from making a call to the server (without an XHR request the call would go to the server, causing the entire web page to be reloaded). The XHR request is handled - either data is sent to the controller to be stored in the database, or data is retrieved by the controller from the database to render on the web page. Finally, part of the web page is updated asynchronously.</p>

<p>A typical XHR get request:</p>
<img src="ajax-request.JPG" alt="XHR Request" height="45%" width="60%">

