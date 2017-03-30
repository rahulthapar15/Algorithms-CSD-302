
import javax.swing.*;
import java.awt.*;
import java.awt.geom.RoundRectangle2D;
import java.awt.geom.RoundRectangle2D.Double;
import java.util.Random;

public class TowersComponent extends JPanel {


	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private MainGUI gui;
	private TowerRingsList rings;
	private TowersModel hanoi;
	//
	public static final int PEGWIDTH = 20;
	public static final int PEGHEIGHT = 400;
	public static final int PEG_Y = 120;
	public static final int BASE_X = 50;
	public static final int BASE_TOP = 480;
	//
	public static final int BASEHEIGHT = 20;
	public static final int BASELENGTH  = 850;
	public static final int BASE_Y = 500;
	//
	public static final int ROUNDNESS = 32;
	//towers frame
	private RoundRectangle2D.Double base;
	private RoundRectangle2D.Double pegOne;
	public static final int P_ONE_BASE = BASE_X + 115;
	private RoundRectangle2D.Double pegTwo;
	public static final int P_TWO_BASE = BASE_X + 415 ;
	private RoundRectangle2D.Double pegThree;
	public static final int P_THREE_BASE = BASE_X + 715;
	private JLabel label;
	private int numMoves;

	public TowersComponent(MainGUI g, TowerRingsList rings, TowersModel model) {
		//not used yet
		gui = g;
		this.rings = rings;
		this.hanoi = model;
		numMoves = 0;
		label = new JLabel("Number of Moves: "+ numMoves);
		label.setAlignmentX(50);
		add(label);
		//building towers of hanoi frame
		base = new RoundRectangle2D.Double(BASE_X, BASE_Y, BASELENGTH, BASEHEIGHT, ROUNDNESS, ROUNDNESS);
		pegOne = new RoundRectangle2D.Double(P_ONE_BASE,PEG_Y, PEGWIDTH, PEGHEIGHT, ROUNDNESS, ROUNDNESS );
		pegTwo = new RoundRectangle2D.Double(P_TWO_BASE,PEG_Y, PEGWIDTH, PEGHEIGHT, ROUNDNESS, ROUNDNESS );
		pegThree = new RoundRectangle2D.Double(P_THREE_BASE,PEG_Y, PEGWIDTH, PEGHEIGHT, ROUNDNESS, ROUNDNESS );
		//
		//should get black thing
	}
	

	public int getNumMoves() {
		return numMoves;
	}


	public void setNumMoves(int numMoves) {
		this.numMoves = numMoves;
		label.setText("Number of Moves: "+ numMoves);
	}


	public void hanoi() {
		hanoi.towers(5,P_ONE_BASE,P_THREE_BASE,P_TWO_BASE);
	}

	public void paintComponent(Graphics g) {
		
		  Graphics2D g2 = (Graphics2D) g;
	      g2.setColor(Color.BLACK);
	      g2.fill(base);
	      g2.fill(pegOne);
	      g2.fill(pegTwo);
	      g2.fill(pegThree);
	      Random r = new Random();      
	      rings.draw(g2);
	}
}
