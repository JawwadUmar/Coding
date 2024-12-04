public class MyClass implements MyInterface{

    static void staticMethod(){
        System.out.println("another static method in Class");
    }

    public static void main(String[] args) {

        //both are valid and have different behaviour
        MyInterface.staticMethod();
        MyClass.staticMethod();
        
    }
}

//Both class and interface can have static methods with same names, and neither overrides other!
