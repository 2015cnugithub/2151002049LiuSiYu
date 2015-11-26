package sphere;

import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.math.BigDecimal;

public class GraphicsController implements MouseMotionListener{
	private Sphere sphere;
	
	public GraphicsController(Sphere sphere) {
		this.sphere = sphere;
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		
	Point p  = e.getPoint();
	if(p.getX()>=p.getY())
		sphere.setRadius(p.getX()/2);
	else
		sphere.setRadius(p.getY()/2);
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

}
