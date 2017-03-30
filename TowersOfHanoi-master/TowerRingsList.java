
import java.awt.Graphics2D;
public class TowerRingsList {
	public TowerRing[] rings;
	private int numRings;
	public TowerRingsList() {
		super();
		// TODO Auto-generated constructor stub
	}
	public TowerRingsList( int numRings, int from) {
		super();
		this.rings = new TowerRing[numRings + 1];
		this.numRings = numRings;
		int offSetY = 0;
		int ringLength = TowerRing.BASE_LENGTH * numRings;
		if(numRings <= 8)
				ringLength= ringLength + 40;
		for(int i = numRings; i >= 1; i--){
			rings[i] = new TowerRing(from, TowersComponent.BASE_TOP - offSetY);
			TowerRing ring = rings[i];
			ring.setRingLength(ringLength);
			ringLength = ringLength - 20;
			offSetY = offSetY + TowerRing.RING_HEIGHT;
		}


	}
	
	public void setHeights(){
		int peg = 0;
		int peg2 = 0;
		int count = 0;
		for(int i = 1; i <= numRings; i++){
			count = 0;
			TowerRing ring = getRing(i);
			peg = ring.getPeg();
			for(int j = i; j <= numRings; j++){
				TowerRing ring2 = getRing(j);
				peg2 = ring2.getPeg();
				if(peg2 == peg){
					count++;
				}
				ring.setyTop(count);
			}
			
		}
		
	}

	public TowerRing getRing(int i){
		return rings[i];
	}

	public void draw(Graphics2D g2){
		setHeights();
		for(int i = 1; i <= numRings; i++){
			TowerRing ring = rings[i];
			ring.draw(g2);
		}
	} 

}
