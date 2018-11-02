package algorithm.sort;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Random;

public class HeapSort<E> extends Sort <E> {

	private class Node{
		
		public E value;
		public Node left;
		public Node right;
		public Node parent;
		
		public Node(E e){
			value = e;
			left = null;
			right = null;
			parent = null;
		}
		
	}
	
	private int level;
	private Node root;
	private Node terminate;
	
	public HeapSort(ArrayList<E> source, Comparator<E> comp) {
		super(source, comp);
		root = null;
		terminate = null;
		// TODO Auto-generated constructor stub
	}

	@Override
	public void sort() {
		// TODO Auto-generated method stub
		
		int i=0;
		if(root==null){
			root = new Node(source.get(i));
			terminate = root;
			i++;
		}
		
		for(int l=i ; l < source.size() ; l++)
			put(source.get(l));
		
		
		isFinishSorting = true;
	}
		

	public void put(E newElement){
		
		Node newNode = new Node(newElement);
		newNode.left = null;
		newNode.right = null;
		newNode.parent = null; 
		
		putAt(terminate, newNode);
			
		Node dest = terminate;
		Node child = newNode;
		while(dest!=root){
			
			//>
			if( comparator.compare(dest.value, newElement) == 1 ? true : false){
				break;
			}
			
			swapOfNode(dest, newNode);
			child = dest;
			dest = dest.parent;
			
		}
		
	}
	
	private void putAt(Node destNode, Node newNode){
		
		
		
		if(destNode.left == null){			
			destNode.left = newNode;
			newNode.parent = destNode;
			terminate = newNode;
		}
		else if(destNode.right == null){
			destNode.right = newNode;
			newNode.parent = destNode;
			terminate = newNode;
		}
		else{
			boolean isLeft = (new Random()).nextBoolean();
			if(isLeft)
				putAt(destNode.left, newNode);
			else
				putAt(destNode.right, newNode);
			terminate = newNode;
		}
		
	}
	
	private void swapOfNode(Node dest, Node newNode){
		
		E temp = newNode.value;
		newNode.value = dest.value;
		dest.value = temp;
		
	}
	
	public E remove(){
		E e = null;
		return e;
	}
	
	public E get(){
		E e = null;
		return e;
	}
	
	public boolean contains(){
		return true;
	}
	
	@Override
	public void printSortingProcess() {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(preorder(root, sb));
		
		return sb.toString();
	}
	
	private E preorder(Node node,StringBuilder sb){
						
		if(node.left!=null)
			sb.append(preorder(node.left, sb) + " ");
		else if(node.right!=null)
			sb.append(preorder(node.right, sb) + " ");
		
		sb.append(node.value + " " );
		return node.value;
	}
	
}
