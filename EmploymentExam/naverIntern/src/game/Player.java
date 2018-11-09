package game;

import java.util.ArrayList;
import card.Card;

public class Player {

	private int playerNumber;
	
	private ArrayList<Card> cards;
	private int sumPoint;
	
	public Player(int num){
		
		cards = new ArrayList<Card>();
		
		playerNumber = num;
		sumPoint =0;
	}
	
	public int getPlayerNumber(){
		return playerNumber;
	}
	
	public void setPlayerNumber(int number){
		playerNumber = number;
	}
	
	public int getSumPoint(){
		return sumPoint;
	}
	
	public void addCard(Card card){
		
		cards.add(card);
		
	}
	
	public ArrayList<Card> getAllCards(){
		return cards;
	}
	
	public void doSumCardsPoint(){
		
		int sum=0;
		
		for(int i=0 ; i < cards.size() ; i++)
			sum += cards.get(i).getPoint();
		
		sumPoint = sum;
	}
	
	public String toString(){
		
	
		StringBuilder bld = new StringBuilder("Player:").append(playerNumber).append(" ");
		for(Card card : cards){
			bld.append(card.toString() + " ");
		}
		bld.append(" : ").append("sum = ").append(sumPoint);
		return bld.toString();
	
	}
}
