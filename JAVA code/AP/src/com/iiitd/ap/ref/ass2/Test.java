import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import javax.script.ScriptEngine;
public class Test {
	Test(){
		
	}
	public static void main(String[] args) throws ScriptException{
		ScriptEngineManager mgr = new ScriptEngineManager();
		ScriptEngine engine = mgr.getEngineByName("JavaScript");
		String infix = "3+2*4+5.2";
		System.out.println(engine.eval(infix));
		
	}
}
