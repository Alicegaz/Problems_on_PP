using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    public interface optional_treatment
    {
        void assigned_to_patient(Patient p);
        Patient reassigned_from_patient(Patient p);
        string give_prescription(string pres);
        string inform_of_hospital_service(Patient p);
        string diagnose(Patient p);
        string prescribe_therapy(Patient p);
    }
    public interface secondary_treatment
    {
        string recomendation(Patient p);
        void observe_the_state(Patient p);
        void take_care(Patient P);
        void control_medication(Patient p);
        void give_medecine(Patient p);
    }
    public interface clinical_nurse_edu_duty
    {
        void contribute_development(Nurse_list nurses);
        void support_staff();
        void precept(Staff new_staff);
        void prof_development(Nurse_list nurses);
    }
    public interface clinical_nurse_specialist : unit_management, nursing_staff_management
    {
        void anlyze_state(Patient p);
        void educate_patient(Patient p);
    }
    public interface coordination_of_patient_services
    {
        bool liaison_health_care_disciplines();
        void services_orchestration();
        void monitore_transport_services();
    }
    public interface unit_management
    {
        void implement_hospital_serv_policy();
        void impliment_health_policy();
        bool environment_safe();
        EquipmentState monitore_equipment();
        SupplyState monitore_supplies();
        CleaningSerState monitore_clean_serv();
    }
    public interface client
    {
        void check_in(date d);
        void leave(date d);
        void visit_doctor(Doctor d);
        void pay(int money);
        bool is_free();
    }
    public interface nursing_staff_management
    {
        void co_ordinate_act(Nursing_act_list activity_list);
        void train_staff(Nurse_list list);
        Dep allocate_staff(Nurse[] list);
        String implement_new_practice(Patient p);
    }
    public class Dep : Hospital
    {

    }
    public class State
    {

    }
    public class EquipmentState : State
    {

    }
    public class CleaningSerState : State
    {

    }
    public class SupplyState : State
    {

    }
    public class Nursing_act
    {

    }
    public class Nursing_act_list
    {
        Nursing_act[] list;
    }
    public class Nurse_list
    {
        Nurse[] list;
    }
    public class Hospital
    {

    }
    public class Staff : Hospital
    {

    }
    public class Medicians : Staff
    {

    }
    public class Cook : Staff
    {

    }
    public class Doctor : Medicians, optional_treatment, secondary_treatment
    {
        Patient[] list;
        string []drugs_list;
        int i = 0;
        int j = 0;
        int h = 0;
        int i1 = 0;
        Disease[] diseases;
        string []hospital_service;
        string[] therapy;
        string[] recomendation_list;
        int i2 = 0;
        int l = 0;
        public void assigned_to_patient(Patient p)
        {
            list[i] = p;
            i++;
        }
        public void set_disease(Disease d)
        {
            diseases[h] = d;
            h++;
        }
        public void set_recomendation(string d)
        {
            recomendation_list[i2] = d;
            i2++;
        }
        public void set_therapy(string n)
        {
            therapy[i1] = n;
            i1++;
        }
        public void set_hospital_service(string serv)
        {
            hospital_service[l] = serv;
            l++;
        }
        public Patient reassigned_from_patient(Patient p)
        {
            for (i=0; i<list.Length; i++)
            {
                if(list[i].get_id() == p.get_id())
                {
                    list[i] = null;
                }
            }
            return p;
        }
        public string give_prescription(string recepie)
        {
            drugs_list[j] = recepie;
            j++;
            return recepie; 
        }
        public string inform_of_hospital_service(Patient p)
        {
            for (int i = 0; i< p.disease_num(); i++)
            {
                for (int j = 0; j < diseases.Length; j++)
                {
                    if (p.get_name_disease(i) == diseases[j].get_name())
                    {
                        return hospital_service[j];
                    }
                }
            }
            return "Cannot recommend anything";
        }
        public string diagnose(Patient p)
        {
            return "";
        }
        public string prescribe_therapy(Patient p)
        {
            for (int i = 0; i < p.disease_num(); i++)
            {
                for (int j = 0; j < diseases.Length; j++)
                {
                    if (p.get_name_disease(i) == diseases[j].get_name())
                    {
                        return therapy[j];
                    }
                }
            }
            return "Cannot recommend anything";
        }
        public string recomendation(Patient p)
        {
            for (int i = 0; i < p.disease_num(); i++)
            {
                for (int j = 0; j < diseases.Length; j++)
                {
                    if (p.get_name_disease(i) == diseases[j].get_name())
                    {
                        return recomendation_list[j];
                    }
                }
            }
            return "Cannot recommend anything";
        }
        public void observe_the_state(Patient p)
        {

        }
        public void take_care(Patient P)
        {

        }
        public void control_medication(Patient p)
        {

        }
        public void give_medecine(Patient p)
        {

        }
    }
    public class Nurse : Medicians, secondary_treatment
    {
        string []diseases_list_general;
        string[] recomendation_list;
        int j = 0;
        int i = 0;
        Dep address;
        public void set_address(Dep d)
        {
            address = d;
        }
        void set_disease(string d)
        {
            diseases_list_general[i] = d;
            i++;
        }
        void set_recomendation(string re)
        {
            recomendation_list[j] = re;
            j++;
        }
        public string recomendation(Patient p)
        {
            for (int i = 0; i < p.disease_num(); i++)
            {
                for (int j = 0; j < diseases_list_general.Length; j++)
                {
                    if (p.get_name_disease(i) == diseases_list_general[j])
                    {
                        return recomendation_list[j];
                    }
                }
            }
            return "Cannot recommend anything";
        }
        public void observe_the_state(Patient p)
        {

        }
        public void take_care(Patient P)
        {

        }
        public void control_medication(Patient p)
        {

        }
        public void give_medecine(Patient p)
        {

        }
    }
    public class Nursing_unit_manager : Nurse, coordination_of_patient_services, unit_management, nursing_staff_management
    {
        Dep []dep_list;
        int i = 0;
        string []new_practice;
        int i1 = 0;
        Patient []patients_adj_list;
        bool env_safe;
        bool know_health_care;
        SupplyState state;
        CleaningSerState state_ser;
        EquipmentState state_equip;

        public void set_equip(EquipmentState s)
        {
            state_equip = s;
        }
        public void set_ser(CleaningSerState s)
        {
            state_ser = s;
        }
        public void set_supplay_state(SupplyState s)
        {
            state = s;
        }
        public void set_patients(Patient []list)
        {
            patients_adj_list = list;
        }
        public void set_know_health_care(bool know)
        {
            know_health_care = know;
        }
        void set_env(bool st)
        {
            env_safe = st;
        }
        public void implement_hospital_serv_policy()
        {

        }
        public void impliment_health_policy()
        {

        }
        public bool environment_safe()
        {
            return env_safe;
        }
        public EquipmentState monitore_equipment()
        {
            return state_equip;
        }
        public SupplyState monitore_supplies()
        {
            return state;
        }
        public CleaningSerState monitore_clean_serv()
        {
            return state_ser;
        }
        public bool liaison_health_care_disciplines()
        {
            return know_health_care;
        }
        public void services_orchestration()
        {

        }
        public void monitore_transport_services()
        {

        }
        public void co_ordinate_act(Nursing_act_list activity_list)
        {

        }
        public void train_staff(Nurse_list list)
        {

        }
        public Dep allocate_staff(Nurse[] list)
        {
            Dep dep = dep_list[i++];
            for (int i = 0; i < dep_list.Length; i++)
            {
              list[i].set_address(dep);
             }
            return dep;
        }
        public String implement_new_practice(Patient p)
        {
         for (int i = 0; i < patients_adj_list.Length; i++)
            {
                for (int j = 0; j < new_practice.Length; j++)
                {
                    if (patients_adj_list[i] == p)
                    {
                        return new_practice[j];
                    }
                }
            }
            return "No such patient in recomendation list";   
        }
    }
    public class clinical_nurse_educator : Nurse, clinical_nurse_edu_duty
    {
        public void contribute_development(Nurse_list nurses)
        {

        }
        public void support_staff()
        {

        }
        public void precept(Staff new_staff)
        {

        }
        public void prof_development(Nurse_list nurses)
        {

        }
    }

    public class date
    {
        int day;
        int year;
        int month;
    }
    public class Disease
    {
        string name;
        public void set_name(string n)
        {
            name = n;
        }
        public string get_name()
        {
            return name;
        }
    }
    public class Patient : Person, client
    {
        private int id = 0;
        bool free;
        Doctor[] doctors;
        int i = 0;
        int j = 0;
        int[] payment_list;
        date []in_hosp_date;
        date []out_hosp_date;
        string name;
        int k = 0;
        int t = 0;
        Disease[] disease_list;
        int m;
        int num = 0;
        Patient()
        {
            id++;
        }
        public int get_id()
        {
            return id;
        }
        public void check_in(date d)
        {
            in_hosp_date[k] = d;
            k++;
        }
        public string get_name_disease(int i)
            {
                  return disease_list[i].get_name();
            }
        public void leave(date d1)
        {
            out_hosp_date[t] = d1;
            t++;
        }
        public void set_disease(string d)
        {
            disease_list[k].set_name(d);
            m++;
            num++;
        }
        public void cure(string d)
        {
            for (int i = 0; i<disease_list.Length; i++)
            {
                if (disease_list[i].get_name() == d)
                {
                    disease_list[i] = null;
                }
            }
            disease_list[k].set_name(d);
            m--;
            num--;
        }
        public string get_disease(int i)
        {
            return disease_list[i].get_name();
        }
        public string get_disease(string n)
        {
            for (int i = 0; i < disease_list.Length; i++)
            {
                if (disease_list[i].get_name().CompareTo(n) == 0)
                {
                    return disease_list[i].get_name();
                }
            }
            return "No sush disease";
        }
        public int disease_num()
        {
            return num;
        } 
        public void set_free()
        {
            free = true;
        }
        public string get_name()
        {
            return name;
        }
        public bool is_free()
        {
            return free;
        }
        public void visit_doctor(Doctor d)
        {
            doctors[i] = d;
            i++;
        }
        void set_name(string name)
        {
            this.name = name;
        }
        public void pay(int p)
        {
            payment_list[j] = p;
            j++;
        }
    }
    public class Person
    {

    }
    public class Receptionist : Staff
    {

    }

    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
