package org.jawwad;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

//A servlet in Spring (or Java in general) is a Java class that handles HTTP requests and responses in a web application. It processes user requests, interacts with backend logic, and sends responses

public class HelloServlet extends HttpServlet {

    public void service(HttpServletRequest request, HttpServletResponse response){
        System.out.println("Inside servlet service");
    }
}
