
/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import java.util.ArrayList;

public class Manager {
    private Photographer dummy = new Photographer();
    private ArrayList<String> photographers = new ArrayList<String>();
    private java.util.PriorityQueue<Assignment> toDoList = new java.util.PriorityQueue<Assignment>();
    private Portfolio thePortfolio = new Portfolio();

    public void hire(String photographer) { photographers.add(photographer); }

    public void giveOutAssignments() {
        for(String photographer : photographers) {
            // get an assignment with the highest priority:
            Assignment assignment = toDoList.poll();
            if(assignment == null)
                break;
            // let the photographer carry out the assignment:
            String filename = dummy.takePicture(assignment.getDescription());
            thePortfolio.addFinishedPhoto(filename, photographer);
        }
    }

    public void newAssignment(int priority, String description) {
        toDoList.offer(new Assignment(priority, description));
    }

    public void checkPortfolio() { /* do nothing */ }
}