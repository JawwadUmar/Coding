 package io.deliveroo.demo;

import java.util.*;

public class Robot {
    int idx = 0;
    List<String> directions = List.of("East", "North", "West", "South");
    List<List<Integer>> delPos = List.of(List.of(1, 0), List.of(0, 1), List.of(-1, 0), List.of(0, -1));
    int width;
    int height;
    int current_x = 0;
    int current_y = 0;
    boolean moved = false;
    ArrayList<ArrayList<Integer>> perimeter = new ArrayList<>();
    Map<List<Integer>, List<Integer>> dp = new HashMap<>();

    public Robot(int width, int height) {
        this.width = width;
        this.height = height;
        perimeter.add(new ArrayList<>(List.of(0, 0, 3)));
        for(int x = 1; x < width; x++){
            perimeter.add(new ArrayList<>(List.of(x, 0, 0)));
        }

        for(int y = 1; y<height; y++){
            perimeter.add(new ArrayList<>(List.of(width-1, y, 1)));
        }

        for(int x = width-2; x>=0; x--){
            perimeter.add(new ArrayList<>(List.of(x, height-1, 2)));
        }

        for(int y = height-2; y>=1; y--){
            perimeter.add(new ArrayList<>(List.of(0, y, 3)));
        }
    }

    public void step(int num) {
        moved = true;
        idx = (idx + num)%(perimeter.size());
        current_x =  perimeter.get(idx).get(0);
        current_y = perimeter.get(idx).get(1);
    }

    public int[] getPos() {
        return new int[]{current_x, current_y};

    }

    public String getDir() {
        if(moved == false){
            return "East";
        }
        return directions.get(perimeter.get(idx).get(2));
    }
}