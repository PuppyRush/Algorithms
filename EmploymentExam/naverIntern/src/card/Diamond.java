package card;

public enum Diamond implements Card{

	D1(1),
	D2(2),
	D3(3),
	D4(4),
	D5(5),
	D6(6),
	D7(7),
	D8(8),
	D9(9),
	D10(10),
	D11(11),
	D12(12),
	D13(13);
	
	private int point;
	
	private Diamond(int num){
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
