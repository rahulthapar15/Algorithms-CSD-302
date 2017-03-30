import javax.swing.JOptionPane;


public class TowersModel {
	
	//towers (3 , 'a','b','c')
	TowerRingsList rings;
	TowersComponent comp;
	MainGUI g;
	int time;
	
	public TowersModel(MainGUI g, int x, int time,int from){
		this.g = g;
		this.time = time;
		rings = new TowerRingsList(x,from);
		comp = new TowersComponent(g, rings, this);
		g.add(comp);
	}
	public void reset(){
		String in = JOptionPane.showInputDialog("How many rings: ");
		if(in == null)
			System.exit(1);
		 int x = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("seconds between moves:(hint .5 for half sec)");
		double time = Double.parseDouble(in);
		if(in == null)
			System.exit(1);
		in = JOptionPane.showInputDialog("\"From\" Peg:");
		if(in == null)
			System.exit(1);
		int from = Integer.parseInt(in);
		
		this.time = (int) (time * 1000);
		g.remove(comp);
		rings = new TowerRingsList(x,g.calcPeg(from));
		comp = new TowersComponent(g, rings, this);
		g.add(comp);
	}
	
	public void towers(int n, int fromPeg, int toPeg, int auxPeg){
		if(n == 1){
			TowerRing ring = rings.getRing(n);
			ring.moveToPeg(toPeg);
			comp.setNumMoves(comp.getNumMoves() + 1);
			g.repaint();
			try {
				Thread.sleep(time);
			} catch (InterruptedException e) {
				System.err.println(e);
				System.exit(1);
			}
			return ;
		}
		if(n != 1){
			towers(n - 1, fromPeg, auxPeg, toPeg);
			System.out.println("" + n);
			TowerRing ring = rings.getRing(n);
			ring.moveToPeg(toPeg);
			comp.setNumMoves(comp.getNumMoves() + 1);
			g.repaint();
			System.err.println("towersModel: " + Thread.currentThread().getName());
			try {
				Thread.sleep(time);
			} catch (InterruptedException e) {
				System.err.println(e);
				System.exit(1);
			}
			
			towers(n - 1, auxPeg, toPeg, fromPeg);
		}
	}

}
