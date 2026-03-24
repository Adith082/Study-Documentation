import java.sql.SQLOutput;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {

    int temp_variable = 40;
    /* main method should always
    * be inside a public class due to which JVM can access the main method
    * in Java, public class name should be same as file
    * */

    /*
    variable is a container that holds a value.
    Java is a static typed language (any variable that we declare, needs to be declared a datatype).
    Java is also a strong typed Language (any datatyped variable can be assigned a range of values only).
     */

    /*

     */
    public static void print_() {
        System.out.println("hellp");
    }

    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        System.out.println("public static void main");
        variables_lecture(); // static method
        String s1 = "abc";
        String s2 = s1;
        s1 += "2";
        System.out.println(s1 + " s1 and s2 " + s2);
        Integer val_ = 5;
        Integer vol_ = 5;
        System.out.println(val_.equals(vol_));
        Main.print_();

        Depressed_lad dl = new Depressed_lad();
        System.out.println("maintain" + dl.maintain);
       // System.out.println(temp_variable);
    }

    public static void variables_lecture() {
        System.out.println("variable lecture part starts");

        char ch = 'a';


        System.out.println("variable lecture ends");
    }

}

