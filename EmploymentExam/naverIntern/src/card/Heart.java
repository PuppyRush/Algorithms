package card;

public enum Heart implements Card{

	H1(1),
	H2(2),
	H3(3),
	H4(4),
	H5(5),
	H6(6),
	H7(7),
	H8(8),
	H9(9),
	H10(10),
	H11(11),
	H12(12),
	H13(13);
	
	private int point;
	
	private Heart(int num){
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
