// Guess the magician's card to win the game
// Characters: Player and magician
// Functions and Objects: player, magician, card, wins, successes, guesses.

// Pseudocode
// Create a player that guesses a magician's card.
// Implement a player, card, wins, successes, and guess function, magician, and magician's card.

var player = {
	card: 0,
	wins: 0,
	success: false,

	guess: function(direction) {
	  	var x = direction;
	  	if(direction === x){
	    this.card = x;
	  	} 

		//Display player's guess
		console.log("Player's guess is " + player.card); 
		// Display where magician's card
		magician.card = Math.floor((Math.random()*10)+1);
		//Let player know if the guess is the magician
		if(player.card === magician.card){
			console.log("Player guessed correctly - player wins!");
			player.success = true;
			player.wins += 1;
		}
		else{
			console.log("Sorry guess again. The magician's card is " + magician.card); 
			player.success = false;
		}
	}
};

var magician = {
card: Math.floor((Math.random()*10)+1)
};

player.guess(1);
player.guess(5);
player.guess(3);
player.guess(9);
player.guess(1);
player.guess(5);
player.guess(3);
player.guess(9);
console.log(player.wins);