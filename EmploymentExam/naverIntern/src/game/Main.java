package game;

import card.Card;

public class Main {

	public static void main(String[] args){
		
		
		GameManager gameManager = new GameManager(4, 100);
		gameManager.setCardPerPlayer(7);
		gameManager.SetCardsForPlayer();
		Player player = gameManager.whoIsWinner();
		
		for(Player ply : gameManager.getAllPlayer()){
			System.out.println(ply);
		}
				
		System.out.println("WINNER : Player" + player.getPlayerNumber());
	}
	
}
