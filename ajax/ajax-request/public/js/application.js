$(document).ready(function () {
  // display the die when the page loads
  var dieHtml = '<div class="die" style="display:none">'
  dieHtml += '<span class="roll">'
  dieHtml += -1
  dieHtml += '</span>'
  dieHtml += '</div>'
  $('form').append(dieHtml);

  // Update the database with die roll, asynchronously update the result on the die  
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