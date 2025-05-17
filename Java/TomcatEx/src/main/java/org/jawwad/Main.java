package org.jawwad;

import org.apache.catalina.LifecycleException;
import org.apache.catalina.startup.Tomcat;

public class Main {
    public static void main(String[] args) throws LifecycleException {
        System.out.println("Hello, World!");
        Tomcat tomcat = new Tomcat();
        tomcat.setPort(9090);
        tomcat.start();
        tomcat.getServer().await();
    }
}