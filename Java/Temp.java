import java.util.List;

class Student{

    Student(int roll, String name, double age){
        this.roll = roll;
        this.name = name;
        this.age = age;
    }
    int roll;
    String name;
    double age;
}

public class Temp {


    public static void main(String[] args) {
        Student student1 = new Student(45, "Rahul", 12);
        Student student2 = new Student(44, "Ismail", 12);
        Student student3 = new Student(43, "Abd", 11);

        List<Student> students = List.of(student1, student2, student3);
        List<String> res = students.stream().filter(n->n.roll > 43).map(n->n.name).toList();

        System.out.println(res);

    }


}
