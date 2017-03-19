#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

class Year{
private:

    bool BS1;
    bool BS2;
    bool BS3;
    bool MS1;
    bool MS2;
    string current;
public:
    Year()
    {

    }
    Year(const Year& y)
    {
     BS1 = y.BS1;
     BS2 = y.BS2;
     BS3 = y.BS3;
     MS1 = y.MS1;
     MS2 = y.MS2;
     current = y.current;
    }
    Year(string str)
    {
        if (str[0] == 'B')
        {
            if (str[2] == '1')
            {
                BS1 = true;
                current  = "BS1";
            }
            else
            if (str[2] == '2')
            {
                BS2 = true;
                current  = "BS2";
            }
            else
            if (str[2] == '3')
            {
                BS3 = true;
                current  = "BS3";
            }

        }
        else if (str[0] == 'M')
        {
            if (str[2] == '1')
            {
                MS1 = true;
                current  = "MS1";
            }
            else if (str[2] == '2')
            {
                MS2 = true;
                current  = "MS2";
            }
        }
    }
    string get_year()
    {
        return current;
    }
    void reset_year( string year)
    {
        current  = year;
    }
    ~Year()
    {

    }
};

class Grade{
   public:
    bool A;
    bool B;
    bool C;
    bool D;
    bool F;
    string current;

    void set_grade(string g)
    {
        if (g.compare("A"))
        {
            A = true;
            current = "A";
        }
        else if (g.compare("B"))
        {
            B = true;
            current = "B";
        }
        else if (g == "C")
        {
            C = true;
            current = "C";
        }
        else if (g == "D")
        {
            D = true;
            current = "D";
        }
        else if (g == "F")
        {
            F = true;
            current = "F";
        }
    }
    string get_grade()
    {
        return current;
    }
};
enum Gender{M, F};
class Name{
private:

public:
    string firstName;
    string familyName;
    Name()
    {

    }
    Name(string fName, string famName)
    {
        firstName = fName;
        familyName = famName;
    }
    Name(const Name& n)
    {
        firstName = n.firstName;
        familyName = n.familyName;
    }
    void set_name(string f_n){
    firstName = f_n;
    }
    void set_surname(string s_n)
    {
        familyName = s_n;
    }
    void set_name_full(string n1, string n2)
    {
        firstName = n1;
        familyName = n2;
    }
    string get_name()
    {
        return firstName;
    }
    string get_surname()
    {
        return familyName;
    }
    Name& operator=(const Name el)
                     {
                         this->firstName = el.firstName;
                         this->familyName = el.familyName;
                         return *this;
                     }
};
class LectureCourse{
        string title;
        Year year;
        //Instructor instructor;
        //AssistantsList assistants;
        bool elective;
        Grade grade;
    public:
        LectureCourse* next;
        int n;
        int i;

        int assist_size = 0;
        LectureCourse(const LectureCourse &l)
        {
            n = 10;
            i = 0;
            next = l.next;
            title = l.title;
            year = l.year;
            //instructor = l->instructor;
            //assistants = l->assistants;
            elective = l.elective;
        }
        LectureCourse(string t)
        {
            n = 10;
            i = 0;
            title = t;
        }
        void set_grade(string a)
        {
            grade.set_grade(a);
        }
        string get_grade()
        {
            return grade.get_grade();
        }
        string get_title()
        {
            return this->title;
        }
        void set_year(Year y)
        {
            year = y;
        }
        void set_elective(bool l)
        {
            elective = l;
        }
        bool is_elective()
        {
            return elective;
        }
        void set_title(string titl)
        {
            this->title = title;
        }
        string get_year()
        {
            year.get_year();
        }

};

class LecturesList{
private:
    LectureCourse* head;
    LectureCourse* current;
    int num;
public:
    LecturesList()
    {
        head = NULL;
        current = NULL;
        num = 0;
    }
    LecturesList(const LecturesList &l): num(0), head(NULL), current(NULL)
    {
        LectureCourse* t = l.head;
        head = t;
        current = head;
        while (current!=NULL)
        {
            this->add(current->next);
            current = current->next;
        }
    }
    LectureCourse* get_head()
    {
     assert(head!=NULL);
     return head;
    }
    void display()
    {
        LectureCourse* curr = head;
        while(curr!=NULL)
        {
            cout << curr->get_title() << ' ' << endl;
            curr = curr->next;
        }
    }
    void display_grades()
    {
        LectureCourse* curr = head;
        while(curr!=NULL)
        {
            cout << curr->get_title() << ' ' << curr->get_grade()<<"\n"<< endl;
            curr = curr->next;
        }
    }
    void add(LectureCourse* c)
    {
        if (head==NULL)
        {
            head = c;
            current = head;
        }
        else
        {
            current->next = c;
            current = current->next;
        }
        num++;
    }
    string& remove_at(int in)
    {
        assert(this->size()!=0);
        LectureCourse* curr;
        if (this->size()==1 && in == 1)
        {
            head = NULL;
            current = head;
        }
        int i = 1;
        LectureCourse* rem = head;
        while(i!=in)
        {
            curr = rem;
            rem = rem->next;
            i++;
        }
        curr->next = rem->next;
        delete rem;
        num--;
        string rem_val= rem->get_title();
        return rem_val;
    }
    string& remove_the(LectureCourse* in)
    {
        assert(this->size()!=0);
        LectureCourse* curr;
        if (this->size()==1 && curr->get_title() == in->get_title())
        {
            head = NULL;
            current = head;
        }
        int i = 1;
        LectureCourse* rem = head;
        while(curr->get_title()!=in->get_title())
        {
            curr = rem;
            rem = rem->next;
            i++;
        }
        curr->next = rem->next;
        delete rem;
        num--;
        string rem_val= rem->get_title();
        return rem_val;
    }
    int size()
    {
        return num;
    }
    string& get_at(int in)
    {
        assert(in>=0 && in < num);
        assert(this->size()!=0);
        LectureCourse* find_val = head;
        int i= 1;
        while(i!=in)
        {
            find_val = head->next;
            i++;
        }
        string find_val_name = find_val->get_title();
        return find_val_name;
    }
    string& operator[](int index){
        return get_at(index);
    }
    bool course_in(string c)
    {
        assert(this->size()!=0);
        LectureCourse* find_val = head;
        bool in;
        int i= 1;
        while(find_val->get_title()!=c && i<this->size())
        {
            find_val = head->next;
            i++;
        }
        if (i == this->size() && find_val->get_title()!=c)
        {
            in = false;
        }
        else
        {
            in = true;
        }
        //string find_val_name = find_val->get_title();
        return in;
    }
    bool course_in(LectureCourse& c)
    {
        assert(this->size()!=0);
        LectureCourse* find_val = head;
        int i= 1;
        bool in;
        while(head->get_title()!=c.get_title())
        {
            find_val = head->next;
            i++;
        }
        //string find_val_name = find_val->get_title();
        if (i == this->size() && find_val->get_title()!=c.get_title())
        {
            in = false;
        }
        else
        {
            in = true;
        }
        return in;
    }
    LectureCourse* course_find(LectureCourse& c)
    {
        assert(this->size()!=0);
        LectureCourse* find_val = head;
        int i= 1;
        while(find_val->get_title().compare(c.get_title())!=0)
        {
            find_val = head->next;
            i++;
        }
        //string find_val_name = find_val->get_title();
        assert(find_val!=NULL || find_val->get_title().compare(c.get_title())!=0);
        return find_val;
    }
    LectureCourse* course_find(string c)
    {
        assert(this->size()!=0);
        LectureCourse* find_val = head;
        int i= 1;
        while(find_val->get_title().compare(c)!=0 && i<this->size())
        {
            find_val = head->next;
            i++;
        }
        assert(find_val!=NULL || (find_val->get_title()).compare(c)!=0);
        return find_val;
        //string find_val_name = find_val->get_title();
    }
    ~LecturesList(void)
    {
        int i = 0;
        while(this->size()!=0)
        {
            this->remove_at(i);
            i++;
        }
    }

};
class Person{
private:
    Gender gender;
    //Laboratory* lab;
public:
    Person()
    {
//        lab = NULL;
    }
    Person(string g)
    {
//        lab = NULL;
        set_gender(g);
    }
    void set_gender(string a)
    {
        if (a.compare("M")==0)
        {
            gender = M;
        }
        else if (a.compare("F"))
        {
            gender = F;
        }
    }
    string get_gender()
    {
        if (gender == M)
        {
            return "M";
        }
        else if (gender == F)
        {
            return "F";
        }
    }
    //Laboratory* get_lab()
    //{
      //  return lab;
    //}
    //string get_name()
    //{
     //   return lab->get_name();
    //}
    //void set_laboratory(Laboratory l)
    //{
      //  lab = new Laboratory(l);
    //}
};
class Instructor : virtual public Person
{
private:
Name name;
LecturesList* lectures;
public:

    Instructor()
    {

    }
    Instructor(string n, string s, string gender):Person(gender)
    {
        name.set_name_full(n, s);
    }
    Instructor(string n, string s)
    {
        name.set_name_full(n, s);
    }
    Instructor(const Instructor &i)
    {
        name = i.name;
        lectures = i.lectures;
    }
    void set_name(string n, string s)
    {
        name.set_name_full(n, s);
    }
    void assign_course(LectureCourse* l)
     {
          lectures->add(l);
     }
     void drop_course(LectureCourse* l)
     {
         lectures->remove_the(l);
     }
     void display_courses()
     {
         lectures->display();
     }
     string get_name()
     {
         return name.get_name();
     }
     string get_surname()
     {

         return name.get_surname();
     }

     ~Instructor()
     {
         delete[] lectures;
     }
};

class Assistant : virtual public Person{
private:
Name name;
LecturesList* lectures;
public:
     Assistant()
     {

     }

    Assistant(string n, string s, string gender):Person(gender)
    {
        name.set_name_full(n, s);
    }
    Assistant(const Assistant &a)
    {
        name = a.name;
        lectures = a.lectures;
    }
    void set_name(string n, string s)
    {
        name.set_name_full(n, s);
    }
    void assign_course(LectureCourse* l)
     {
          lectures->add(l);
     }
     void drop_course(LectureCourse* l)
     {
         lectures->remove_the(l);
     }
     void display_courses()
     {
         lectures->display();
     }
     string get_name()
     {
         return name.firstName;
     }
     string get_surname()
     {
         return name.familyName;
     }
     ~Assistant()
     {
         delete[] lectures;
     }
};
class Student : virtual public Person{
    private:
      Name* name;
      Year year;
      LecturesList *lectures;
    public:
     Student()
     {

     }
     Student(string n, string f, string gender):Person(gender)
     {
         name->set_name_full(n, f);
     }
     Student(string n, string f)
     {
         name->set_name_full(n, f);
     }
     Student(Name& n)
     {
         name = new Name(n);
         //lectures = NULL;
     }
     string get_name()
     {
        return name->firstName;
     }
     string get_surname()
     {
         return name->familyName;
     }
     void set_name_full(string n, string f)
     {
         name->set_name_full(n, f);
     }
     void assign_course(LectureCourse* l)
     {
          lectures->add(l);
     }
     void assign_courses(LecturesList l)
     {
         lectures = new LecturesList(l);
     }
     void drop_course(LectureCourse* l)
     {
         lectures->remove_the(l);
     }
     void display_courses()
     {
         lectures->display();
     }
     void get_grades()
     {
         lectures->display_grades();
     }
     ~Student()
     {
         delete[] lectures;
     }
};


class AssistantsList{
private:
int nextInd;
int length;
int n;
public:
    Assistant *assistants;

    //AssistantsList()
    //{
        //n = 10;
        //assistants = new Assistant[n];
        //lengt = n;
        //nextInd = 0;
    //}
    AssistantsList(const AssistantsList& s)
    {
        n = s.length;
        assistants = s.assistants;
        length = n;
        memcpy(assistants, s.assistants, length*sizeof(Assistant));
        nextInd = length+1;
    }
      void add(Assistant assist)
        {
            Assistant *temp;
            if (nextInd == n)
                {
                temp = new Assistant[n*2];
                memcpy(temp, assistants, sizeof(Assistant)*n);
                delete [] assistants;
                assistants = temp;
                length = n*2;
            }
            assistants[nextInd++] = assist;
        }
        string delete_assist(int in)
        {
            assert(length!=0);
            assert(in<=length && in >= 0);
            Assistant del_el= assistants[in];
            Assistant* temp = (Assistant*)malloc((length-1)*sizeof(Assistant));
            memcpy(temp, assistants, (in - 1)*sizeof(Assistant));
            memcpy(temp+(in*sizeof(Assistant)), assistants+((in+1)*sizeof(Assistant)), (length - in)*sizeof(Assistant));
            length--;
            delete [] assistants;
            assistants = temp;
            return del_el.get_name();
        }

        string delete_assist(Assistant as)
        {
            assert(length!=0);
            int i = 0;
            while (assistants[i].get_name()!=as.get_name())
            {
                i++;
            }
            Assistant del_el = assistants[i];
            Assistant* temp = (Assistant*)malloc((length-1)*sizeof(Assistant));
            memcpy(temp, assistants, (i - 1)*sizeof(Assistant));
            memcpy(temp+(i*sizeof(Assistant)), assistants+((i+1)*sizeof(Assistant)), (length - i)*sizeof(Assistant));
            length--;
            delete [] assistants;
            assistants = temp;
            return del_el.get_name();
        }
        int size()
        {
            return length;
        }
        void display()
        {
        for (int i=0; i<this->size(); i++)
        {
            cout << assistants[i].get_name();
        }
        }
        ~AssistantsList()
        {
            delete []assistants;
        }


};
class LectureCourseTeam
{
    Instructor* instructor;
    AssistantsList* assistants;
    LectureCourse* lecture_course;
public:
    LetureCourseTeam(const LectureCourse &c)
    {
        lecture_course = new LectureCourse(c);
    }
    string get_instructor_name()
        {
            return instructor->get_name();
        }
    string get_instructor_second()
    {
        return instructor->get_surname();
    }
        void add_assistant(Assistant assist)
        {
            assistants->add(assist);
        }
        void display_assisants()
        {
            assistants->display();
        }
        void set_instructor(Instructor i)
        {
            instructor = new Instructor(i);
        }
        void set_assistants(AssistantsList a)
        {
            assistants = new AssistantsList(a);
        }

        ~LectureCourseTeam()
        {
            delete[] assistants;
        }
};



class InstructorsList{
    private:
int nextInd;
int length;
int n;
public:
    Instructor *instructors;

    InstructorsList()
    {
        n = 10;
        instructors = new Instructor[n];
        length = n;
        nextInd = 0;
    }
    InstructorsList(const InstructorsList& s)
    {
        n = s.length;
        instructors = new Instructor[n];
        length = n;
        memcpy(instructors, s.instructors, length*sizeof(Instructor));
        nextInd = length+1;
    }
    void add(Instructor inst){
    Instructor *temp;
            if (nextInd == n)
                {
                temp = new Instructor[n*2];
                memcpy(temp, instructors, sizeof(Instructor)*n);
                delete [] instructors;
                instructors = temp;
                length = n*2;
            }
            instructors[nextInd++] = inst;
        }
        string delete_assist(int in)
        {
            assert(length!=0);
            assert(in<=length && in >= 0);
            Instructor del_el= instructors[in];
            Instructor* temp = (Instructor*)malloc((length-1)*sizeof(Instructor));
            memcpy(temp, instructors, (in - 1)*sizeof(Instructor));
            memcpy(temp+(in*sizeof(Instructor)), instructors+((in+1)*sizeof(Instructor)), (length - in)*sizeof(Instructor));
            length--;
            delete [] instructors;
            instructors = temp;
            return del_el.get_name();
        }

        string delete_assist(Instructor as)
        {
            assert(length!=0);
            int i = 0;
            while (instructors[i].get_name()!=as.get_name())
            {
                i++;
            }
            Instructor del_el = instructors[i];
            Instructor* temp = (Instructor*)malloc((length-1)*sizeof(Instructor));
            memcpy(temp, instructors, (i - 1)*sizeof(Instructor));
            memcpy(temp+(i*sizeof(Instructor)), instructors+((i+1)*sizeof(Instructor)), (length - i)*sizeof(Instructor));
            length--;
            delete [] instructors;
            instructors = temp;
            return del_el.get_name();
        }
        void display()
        {
         for (int i=0; i<length; i++)
         {
             cout << instructors[i].get_name() << ' ';
         }
        }
        int size()
        {
            return length;
        }
        ~InstructorsList()
        {
            delete [] instructors;
        }


};

enum class DayWeek {Monday, Tuesday, Wednesday, Thursday, Fridy, Sundy, Saturday };
class Time{
int hours;
int minutes;
DayWeek day;
public:
    Time(DayWeek d)
    {
        day = d;
    }
    Time(const Time &t)
    {
        hours = t.hours;
        minutes = t.minutes;
        day = t.day;
    }
DayWeek get_day()
{
    return day;
}
void set_hours(int h)
{
    hours = h;
}
void set_minutes(int m)
{
    minutes = m;
}
void set_day(DayWeek d)
{
    day = d;
}
int get_hours()
{
    return hours;
}
int get_minutes()
{
    return minutes;
}
};
class Auditorium{
    Time* working_time;
    int roomNo;
public:
    //Auditorium(int r)
    //{
      //  roomNo = r;
    //}
    Auditorium(const Auditorium &r)
    {
        working_time = r.working_time;
        roomNo = r.roomNo;
    }

    /*void set_time(Time t)
    {
        working_time.time = new Time(t);
    }*/
    int get_no()
    {
        return roomNo;
    }
};
class Lecture{
    LectureCourse* lecture;
    Auditorium* room;
    public:
    Lecture(Auditorium r)
    {
        room = new Auditorium(r);
    }
    void set_course(LectureCourse l)
    {

    }

};
class TeachingDay{
    LecturesList* lectures;
public:
    TeachingDay(const LecturesList &l)
    {
        lectures = new LecturesList(l);
    }
    void get_lectures()
    {
        lectures->display();
    }
};

class TeachingWeek{
    TeachingDay* monday;
    TeachingDay* tuesday;
    TeachingDay *wednesday;
    TeachingDay *thursday;
    TeachingDay *fridy;
    TeachingDay *sunday;
    TeachingDay *saturday;
    int id;
public:
    TeachingWeek()
    {

    }
    TeachingWeek(int i)
    {
        id = i;
    }
    int get_id()
    {
        return id;
    }
    void set_id(int i)
    {
        id = i;
    }
    void set_monday(LecturesList l)
    {
        monday = new TeachingDay(l);
    }
    void set_tuesday(LecturesList l)
    {
        tuesday = new TeachingDay(l);
    }
    void set_wednesday(LecturesList l)
    {
        wednesday = new TeachingDay(l);
    }
    void set_thursday(LecturesList l)
    {
        thursday = new TeachingDay(l);
    }
    void set_fridy(LecturesList l)
    {
        fridy = new TeachingDay(l);
    }
    void set_sunday(LecturesList l)
    {
        sunday = new TeachingDay(l);
    }
    void set_saturday(LecturesList l)
    {
        saturday =new TeachingDay(l);
    }
    TeachingDay* get_monday()
    {
        return monday;
    }
    TeachingDay* get_tuesday()
    {
        return tuesday;
    }
    TeachingDay* get_wednesday()
    {
        return wednesday;
    }
    TeachingDay* get_thursday()
    {
        return thursday;
    }
    TeachingDay* get_fridy()
    {
        return fridy;
    }
    TeachingDay* get_sunday()
    {
        return sunday;
    }
    TeachingDay* get_saturday()
    {
        return saturday;
    }
};
/**
///////////////////////////////////////////////
*/
class TeachingWeeks{
private:
int nextInd;
int length;
int n;
public:
    TeachingWeek *teachig_weeks;

    TeachingWeeks()
    {
        n = 10;
        teachig_weeks = new TeachingWeek[n];
        length = n;
        nextInd = 0;
    }
    TeachingWeeks(const TeachingWeeks& s)
    {
        n = s.length;
        teachig_weeks = new TeachingWeek[n];
        length = n;
        memcpy(teachig_weeks, s.teachig_weeks, length*sizeof(TeachingWeek));
        nextInd = length+1;
    }
    void add(TeachingWeek inst){
    TeachingWeek *temp;
            if (nextInd == n)
                {
                temp = new TeachingWeek[n*2];
                memcpy(temp, teachig_weeks, sizeof(TeachingWeek)*n);
                delete [] teachig_weeks;
                teachig_weeks = temp;
                length = n*2;
            }
            teachig_weeks[nextInd++] = inst;
        }
        int delete_assist(int in)
        {
            assert(length!=0);
            assert(in<=length && in >= 0);
            TeachingWeek del_el= teachig_weeks[in];
            TeachingWeek* temp = (TeachingWeek*)malloc((length-1)*sizeof(TeachingWeek));
            memcpy(temp, teachig_weeks, (in - 1)*sizeof(TeachingWeek));
            memcpy(temp+(in*sizeof(TeachingWeek)), teachig_weeks+((in+1)*sizeof(TeachingWeek)), (length - in)*sizeof(TeachingWeek));
            length--;
            delete [] teachig_weeks;
            teachig_weeks = temp;
            return del_el.get_id();
        }

        int delete_assist(TeachingWeek as)
        {
            assert(length!=0);
            int i = 0;
            while (teachig_weeks[i].get_id()!=as.get_id())
            {
                i++;
            }
            TeachingWeek del_el = teachig_weeks[i];
            TeachingWeek* temp = (TeachingWeek*)malloc((length-1)*sizeof(TeachingWeek));
            memcpy(temp, teachig_weeks, (i - 1)*sizeof(TeachingWeek));
            memcpy(temp+(i*sizeof(TeachingWeek)), teachig_weeks+((i+1)*sizeof(TeachingWeek)), (length - i)*sizeof(TeachingWeek));
            length--;
            delete [] teachig_weeks;
            teachig_weeks = temp;
            return del_el.get_id();
        }
        void display()
        {
         for (int i=0; i<length; i++)
         {
             cout << teachig_weeks[i].get_id() << ' ';
         }
        }
        void schedule_display()
        {
         for (int i=0; i<length; i++)
         {
             teachig_weeks[i].get_monday()->get_lectures();
             teachig_weeks[i].get_tuesday()->get_lectures();
             teachig_weeks[i].get_wednesday()->get_lectures();
             teachig_weeks[i].get_thursday()->get_lectures();
             teachig_weeks[i].get_fridy()->get_lectures();
             teachig_weeks[i].get_saturday()->get_lectures();
             teachig_weeks[i].get_sunday()->get_lectures();
         }
        }
        int size()
        {
            return length;
        }
        ~TeachingWeeks()
        {
            delete [] teachig_weeks;
        }


};

class TeachingSchedule{
    TeachingWeeks* weeks;
    string name;
public:
    TeachingSchedule()
    {
    }
    TeachingSchedule(string n)
    {
        name = n;
    }
    TeachingSchedule(const TeachingSchedule &schedule)
    {        this->weeks = schedule.weeks;
        this->name = schedule.name;
    }
    TeachingSchedule(TeachingWeeks w)
    {
        weeks = new TeachingWeeks(w);
    }
    void set_weeks(TeachingWeeks w)
    {
        weeks = new TeachingWeeks(w);
    }
    void schedule_display()
    {
        weeks->display();
    }

    ~TeachingSchedule()
    {
        delete[] weeks;
    }
};

class Laboratory{
private:
    string name;
    Instructor* leader;
    TeachingSchedule* schedule;
public:
    Laboratory(const Laboratory& l)
    {
        name = l.name;
        leader = l.leader;
        schedule = l.schedule;
    }
    Laboratory(string n)
    {
        name = n;
    }
    void set_schedule(TeachingSchedule sch)
    {
        schedule = new TeachingSchedule(sch);
    }
    void set_schedule(TeachingWeeks sc)
    {
        schedule = new TeachingSchedule(sc);
    }
    void set_name(string n)
    {
        name = n;
    }
    void set_leader(Instructor instr)
    {
        leader = new Instructor(instr);
    }
    string get_name()
    {
        return name;
    }
    Instructor* get_leader()
    {
        return leader;
    }
    TeachingSchedule* get_schedule()
    {
       schedule->schedule_display();
    }
    ~Laboratory()
    {
        delete[] schedule;
    }

};

class Partner
{
    private:
    string company_name;
    string location;
public:
    Partner()
    {
    }
    Partner(const Partner& p)
    {
        company_name = p.company_name;
        location = p.location;
    }
    Partner(string name)
    {
        company_name = name;
        location = "undefined";
    }
    void set_c_name(string c)
    {
        company_name = c;
    }
    ~Partner()
    {

    }

};
class Research_group : virtual public Laboratory
{
    private:
        Partner* company;
        InstructorsList *instructors;
public:
        Research_group(string name):Laboratory(name)
        {
        }

        void set_partner(Partner p)
        {
            company  = new Partner(p);
        }
        void set_partner(string name)
        {
            company->set_c_name(name);
        }
        void add_instructor(Instructor in)
        {
            instructors->add(in);
        }
        string remove_instructor(Instructor in)
        {
            instructors->delete_assist(in);
        }
        ~Research_group()
        {
            delete[] instructors;
        }
};
class StudentsList{

private:
int nextInd;
int length;
int n;
public:
    Student *students;
    StudentsList()
    {
        //n = 10;
        //students = new Student[n];
        length = n;
        nextInd = 0;
    }
    StudentsList(const StudentsList& s)
    {
        n = s.length;
        students = new Student[n];
        length = n;
        memcpy(students, s.students, length*sizeof(Student));
        nextInd = length+1;
    }
        string delete_assist(int in)
        {
            assert(length!=0);
            assert(in<=length && in >= 0);
            Student del_el= students[in];
            Student* temp = (Student*)malloc((length-1)*sizeof(Student));
            memcpy(temp, students, (in - 1)*sizeof(Student));
            memcpy(temp+(in*sizeof(Student)), students+((in+1)*sizeof(Student)), (length - in)*sizeof(Student));
            length--;
            delete [] students;
            students = temp;
            return del_el.get_name();
        }
        void add(Student inst){
            Student *temp;
            if (nextInd == n)
                {
                temp = new Student[n*2];
                memcpy(temp, students, sizeof(Student)*n);
                delete [] students;
                students = temp;
                length = n*2;
            }
            students[nextInd++] = inst;
        }
        string delete_assist(Student as)
        {
            assert(length!=0);
            int i = 0;
            while (students[i].get_name()!=as.get_name())
            {
                i++;
            }
            Student del_el = students[i];
            Student* temp = (Student*)malloc((length-1)*sizeof(Student));
            memcpy(temp, students, (i - 1)*sizeof(Student));
            memcpy(temp+(i*sizeof(Student)), students+((i+1)*sizeof(Student)), (length - i)*sizeof(Student));
            length--;
            delete [] students;
            students = temp;
            return del_el.get_name();
        }
        void display()
        {
         for (int i=0; i<length; i++)
         {
             cout << students[i].get_name() << ' ';
         }
        }
        int size()
        {
            return length;
        }
        ~StudentsList()
        {
            delete [] students;
        }
        //StudentsList& operator=(StudentsList s)
        //{
        //n = s->size();
        //sudents_array = new Student[n];
        //length = n;
        //memccpy(students_array, s->students, length*sizeof(Student));
        //return *this;
        //}
};
class University{
    StudentsList* students;
    AssistantsList* assistants;
    InstructorsList* instructors;
    LecturesList* lectures;
    TeachingSchedule* schedule;
    string name;
    public:
    University(string n)
    {
        name = n;
    }
    void set_students_list(StudentsList s)
    {
        students = new StudentsList(s);
    }
    void set_assistants(AssistantsList assist)
    {
        assistants = new AssistantsList(assist);
    }
    void set_instructors(InstructorsList inst)
    {
        instructors = new InstructorsList(inst);
    }
    void set_lectures(LecturesList *lect)
    {
        lectures = new LecturesList(*lect);
    }
    void set_schedule(TeachingSchedule sch)
    {
        schedule = new TeachingSchedule(sch);
    }
    ~University()
    {
        delete[] instructors;
        delete[] assistants;
        delete[] students;
        delete[] lectures;
        delete[] schedule;
    }

};

class Students_research: virtual public Laboratory
{
    private:
        StudentsList *students;
    public:
        Students_research(string name):Laboratory(name){}
        void add_instructor(Student in)
        {
            students->add(in);
        }
        string remove_instructor(Student in)
        {
            students->delete_assist(in);
        }
        ~Students_research()
        {
            delete[] students;
        }

};




int main()
{
    Student *alice = new Student("Alice", "Gazizullina");
    LectureCourse *lect = new LectureCourse("new maths");
    alice->assign_course(lect);
    return 0;
}
