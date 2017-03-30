import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Point2D;
import java.awt.geom.RoundRectangle2D;
import java.awt.geom.RoundRectangle2D.Double;
import java.util.Random;
public class TowerRing {

	// instance fields
	private double xLeft;
	private double yTop;
	private int peg;
	private int length;
	private int midPoint;
	private Color ringColor;
	TowersComponent comp;
	//
	public static final int RING_HEIGHT = 20;
	public static final int BASE_LENGTH = 21;
	
	/**
	 * Constructs a ring with a given top left corner
	 * 
	 * @param x
	 *            the x coordinate of the top left corner
	 * @param y
	 *            the y coordinate of the top left corner
	 */
	public TowerRing( double x, double y) {
		xLeft = x;
		updatePeg(x);
		yTop = y;
		this.comp = comp;
		this.length = BASE_LENGTH;
		this.midPoint = length / 2;
		Random r = new Random();
		ringColor = new Color(r.nextInt(200), r.nextInt(200), r.nextInt(200));
	}

	public TowerRing() {
	
	}
	
	public int getPeg() {
		return peg;
	}

	public void setPeg(int peg) {
		this.peg = peg;
	}

	public double getyTop() {
		return yTop;
	}

	public void setyTop(int i) {
		this.yTop = TowersComponent.BASE_TOP - (RING_HEIGHT * i) + 20;
	}

	public void move(int num) {
		xLeft += num;
	}
	public void moveToPeg(int num){
		updatePeg(num);
		xLeft = num - midPoint + (TowersComponent.PEGWIDTH / 2);
	}
	public void updatePeg(double x){
		if(x == TowersComponent.P_ONE_BASE){
			peg = 1;
		}
		if(x == TowersComponent.P_TWO_BASE){
			peg = 2;
		}
		if(x == TowersComponent.P_THREE_BASE){
			peg = 3;
		}
	}

	
	
	public Color getRingColor() {
		return ringColor;
	}

	public void setRingColor(Color ringColor) {
		this.ringColor = ringColor;
	}

	public void setRingLength(int length){
		this.length = length;
		this.midPoint = length / 2;
		this.xLeft = xLeft - midPoint + 10;
	}	


	/**
	 * Draws the ring
	 * 
	 * @param g2
	 *            the graphics context
	 */
	public void draw(Graphics2D g2) {
		RoundRectangle2D.Double ring = new RoundRectangle2D.Double(xLeft,yTop, length, RING_HEIGHT, 5, 5);
		g2.setColor(ringColor);
		g2.fill(ring);
	}

}
