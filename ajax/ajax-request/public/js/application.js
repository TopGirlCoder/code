$(document).ready(function () {
  var dieHtml = '<div class="die" style="display:none">'
  dieHtml += '<span class="roll">'
  dieHtml += -1
  dieHtml += '</span>'
  dieHtml += '</div>'
  $('form').append(dieHtml);

  //   1- intercept the form submission event using jQuery
  //   2- prevent the default action for that event from happening
  //   3- use jQuery to submit an AJAX post to the form's action
  //   4- when the AJAX post is done, display the new die roll using jQuery
  //   5- the die shows a random number between 1 and #of sides
  $('form').on('submit',function(e){
    e.preventDefault();

    $.ajax({
      method: 'post',
      url: '/rolls',
      data: $('form').serialize(),
    })

    .done(function(data){
      $('span.roll').text(data.value)
      $('.die').show()
    })
  })
});