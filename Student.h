typedef struct 
{
    int day, month, year;
} birthdate;

typedef struct
{
    char lastName[20];
    char firstName[20];
} name  ;

typedef struct
{
    //student's id
    char id[20];
    
    //student's full name
    name fullName;
    
    //student birthdate
    birthdate birthDay;

    //overall grades of three subjects: Algebra, Calculus, Basic Programming respectively
    float grade[3];

    //function to calculate the gpa
} student;

//funtion to calculate the gpa
float gpa(student thisStudent) {
    return (thisStudent.grade[0] + thisStudent.grade[1] + thisStudent.grade[2])/3;
}

//function to compare the birhtdate of 2 student
bool isYounger(student student_1, student student_2) {
    
    //comparing birth year
    if(student_1.birthDay.year < student_2.birthDay.year) {
        return true;
    }
    
    //comparing birth month
    if(student_1.birthDay.month < student_2.birthDay.month) {
        return true;
    }
    
    //comparing birth date
    if(student_1.birthDay.day < student_2.birthDay.day) {
        return true;
    }

    //if the 2 students have the same birthdate then no one is younger
    return false;
}

// function to check if 2 students have the same birthdate
bool isSameBirthdate(student student_1, student student_2) {
    return (student_1.birthDay.day == student_2.birthDay.day &&
            student_1.birthDay.month == student_2.birthDay.month &&
            student_1.birthDay.year == student_2.birthDay.year);
}

//finding the youngest student
student findYoungest(student *students, int numberOfStudent) {
    
    student youngestStudent = {
                                "", //id
                                {"",""}, //name
                                {32,13,9999}, //birthdate
                                {0.0,0.0,0.0} //grade
                            };

    for(int i = 1; i <= numberOfStudent; ++i) {
        if(isYounger(students[i], youngestStudent)) {
            youngestStudent = students[i];
        }
    }

    return youngestStudent;
}

//finding the oldest student
student findOldest(student *students, int numberOfStudent) {
    student oldestStudent = {
                                "", //id
                                {"",""}, //name
                                {0,0,0}, //birthdate
                                {0.0,0.0,0.0} //grade
                            };

    for(int i = 1; i <= numberOfStudent; ++i) {
        if(isYounger(oldestStudent, students[i])) {
            oldestStudent = students[i];
        }
    }

    return oldestStudent;
}

//finding the students with highest GPA 

//finding the students with GPA student

//finding the students with highest BP grade
