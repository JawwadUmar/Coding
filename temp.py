NUMBER_OF_COMPETITORS = 25
NUM_OF_EVENTS = 5

CompetitorName = ["Elie", "Zayd", "Jae", "Aman", "..."] ## Array of size 25

# 25 * 5
# 25 rows and 5 cols
# COMPETITORSCORE[25][5]
#COMPETITORSCORE[1][2] --> what is this going to represent 

#data type of score --> Real(float) or integer 

COMPETITORSCORE = [[0 for _ in range(NUM_OF_EVENTS)] for _ in range(NUMBER_OF_COMPETITORS)]

#Input scores with Validation
for i in range(NUMBER_OF_COMPETITORS):
    print(f"\nEnter the score for {CompetitorName[i]}")
    for j in range(NUM_OF_EVENTS):
        while True:
            score = int(input(f"Enter the score for Event {j+1} (0-100)"))

            if 0<=score<=100:
                COMPETITORSCORE[i][j] = score
                break
            else:
                print("Invalid input, Score must be between 0 and 100")

#Calculating the highest score for each event
#Output the name of medal receiver for each event 
for j in range(NUM_OF_EVENTS):
    highest = 0
    indexGuyWithHighestScore = -1
    for i in range(NUMBER_OF_COMPETITORS):
        if COMPETITORSCORE[i][j] > highest:
            highest = COMPETITORSCORE[i][j]
            indexGuyWithHighestScore = i
    
    print(f"The highest core for event {j+1} is {highest} and the medal winner for this event is {CompetitorName[indexGuyWithHighestScore]}")

#Points array of size 25
Points = [0]*NUMBER_OF_COMPETITORS #Stores total sum of score

for i in range(NUMBER_OF_COMPETITORS):
    total = 0
    for j in range(NUM_OF_EVENTS):
        total+= COMPETITORSCORE[i][j]
    
    Points[i] = total

highestTotalPoint = 0
highestScoringGuyIndex = -1

for i in range(NUMBER_OF_COMPETITORS):
    if Points[i] > highestTotalPoint:
        highestTotalPoint = Points[i]
        highestScoringGuyIndex = i

print(f"The highest total point is {highestTotalPoint}")
print(f"The guy scoring the highest total point is P{CompetitorName[highestScoringGuyIndex]}")



