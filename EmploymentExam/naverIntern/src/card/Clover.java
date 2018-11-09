package card;

public enum Clover implements Card{

	C1(1),
	C2(2),
	C3(3),
	C4(4),
	C5(5),
	C6(6),
	C7(7),
	C8(8),
	C9(9),
	C10(10),
	C11(11),
	C12(12),
	C13(13);
	
	private int point;
			
	private Clover(int num){
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
