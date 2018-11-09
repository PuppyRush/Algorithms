package card;

public enum Spade implements Card{

	S1(1),
	S2(2),
	S3(3),
	S4(4),
	S5(5),
	S6(6),
	S7(7),
	S8(8),
	S9(9),
	S10(10),
	S11(11),
	S12(12),
	S13(13);
	
	private int point;
	
	private Spade(int num){
		point = num;
	}
	
	@Override
	public String toString(){
		return this.name();
	}
	
	
	public int getPoint(){
		return point;
	}
	
}
