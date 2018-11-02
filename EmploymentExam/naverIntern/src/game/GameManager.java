package game;

import java.util.ArrayList;
import java.util.Random;

import card.*;

public class GameManager {
	
	private int cardPerPlayer;
	private int mixedNumber;
	private ArrayList<Player> players;
	private ArrayList<Card> cards;
		
	public GameManager(int playerNumber, int mixedNumber){
		
		if(getAllCardNumber() % playerNumber != 0)
			throw new IllegalArgumentException("카드의 총 갯수는 플레이어수와 동일하게 나눌 수 있어야합니다.");
		
		this.mixedNumber = mixedNumber;
		cardPerPlayer = getAllCardNumber() / playerNumber;
		
		initPlayers(playerNumber);
		initCards();
		mixCards();
		
	}
	

	private void initPlayers(int num){
		
		players = new ArrayList<Player>(num);
		for(int i=1 ; i <= num; i++)
			players.add( new Player(i));
		
	}
		
	private void initCards(){
	
		cards = new ArrayList<Card>();
		
		
		for(Clover clover : Clover.values())
			cards.add(clover);
		
		for(Diamond dia : Diamond.values())
			cards.add(dia);
		
		for(Heart heart : Heart.values())
			cards.add(heart);
		
		for(Spade spade : Spade.values())
			cards.add(spade);
	}
	
	public ArrayList<Player> getAllPlayer(){
		return players;
	}
	
	private int getAllCardNumber(){
	
		int sumCards = 0;
		
		sumCards += Clover.values().length + Diamond.values().length + 
				Heart.values().length + Spade.values().length;
		
		return sumCards;
	}
	
	public void setCardPerPlayer(int num){
		cardPerPlayer = num;
	}
	
	public void SetCardsForPlayer(){
		
		int round=0;
		int sumCards = cardPerPlayer * players.size();
		
		if(sumCards >= cards.size())
			throw new IllegalArgumentException("선수당 나눠줄 카드의 갯수 총합이 게임의 총 카드수보다 많습니다.");
		
		for(int i=0 ; i < sumCards ; i++){
			
			players.get(round).addCard(cards.get(i));
			
			round++;
			round %= players.size();
		}
		
	}
	
	private void mixCards(){
		
		int i=0;
		Random rdm = new Random();
		
		while(i < mixedNumber){
			
			int leftCardIndex = rdm.nextInt(cards.size());
			int rightCardIndex = rdm.nextInt(cards.size());
			
			Card tempCard = cards.get(leftCardIndex);
			cards.set(leftCardIndex, cards.get(rightCardIndex));
			cards.set(rightCardIndex, tempCard);	
			
			i++;
		}
		
	}
			
	public Player whoIsWinner(){
	
		Player winner = players.get(0);
		int minimalPoint = Integer.MAX_VALUE;

		for(Player ply : players){
			ply.doSumCardsPoint();
						
			if(minimalPoint > ply.getSumPoint()){
				winner = ply;
				minimalPoint = ply.getSumPoint();
			}
		}
		
		if(isRegameCondition(minimalPoint)){
			doReGame();
		}
			
	
		return winner;
	}
	
	
	private boolean isRegameCondition(int minimalPoint){
		
		int samePointNumber=0;
		
		for(Player ply : players){
			if(ply.getSumPoint()==minimalPoint)
				samePointNumber++;
		}
		
		if(samePointNumber>1)
			return true;
		else	
			return false;
	}
	
	private void doReGame(){
		
		mixCards();
		whoIsWinner();
		
	}
	
}
