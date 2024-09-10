import java.io.*;
import java.util.*;

class Doctor {
    private int doctorID;
    private String name;
    private String specialization;
    private String availability;

    public Doctor(int doctorID, String name, String specialization, String availability) {
        this.doctorID = doctorID;
        this.name = name;
        this.specialization = specialization;
        this.availability = availability;
    }

    public int getDoctorID() {
        return doctorID;
    }

    public String getName() {
        return name;
    }

    public String getSpecialization() {
        return specialization;
    }

    public String getAvailability() {
        return availability;
    }

    public void displayAvailability() {
        System.out.println("Doctor availability: " + availability);
    }

    public void saveDoctorInfo() throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("doctors.txt", true));
        writer.write(doctorID + "," + name + "," + specialization + "," + availability + "\n");
        writer.close();
    }
}

class GeneralPractitioner extends Doctor {
    public GeneralPractitioner(int doctorID, String name, String availability) {
        super(doctorID, name, "General Practitioner", availability);
    }

    @Override
    public void displayAvailability() {
        System.out.println(getName() + " is available for walk-ins from " + getAvailability());
    }
}

class Specialist extends Doctor {
    public Specialist(int doctorID, String name, String specialization, String availability) {
        super(doctorID, name, specialization, availability);
    }

    @Override
    public void displayAvailability() {
        System.out.println(getName() + " requires appointments. Available slots: " + getAvailability());
    }
}

class Patient {
    private int patientID;
    private String name;
    private int age;

    public Patient(int patientID, String name, int age) {
        this.patientID = patientID;
        this.name = name;
        this.age = age;
    }

    public int getPatientID() {
        return patientID;
    }

    public String getName() {
        return name;
    }

    public void bookAppointment(Doctor doctor, Appointment appointment) throws IOException {
        System.out.println("Appointment booked for " + name + " with Dr. " + doctor.getName());
        appointment.saveAppointment();
        savePatientInfo();
    }

    public void savePatientInfo() throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("patients.txt", true));
        writer.write(patientID + "," + name + "," + age + "\n");
        writer.close();
    }
}

class Appointment {
    private int appointmentID;
    private int doctorID;
    private int patientID;
    private String date;
    private String time;

    public Appointment(int appointmentID, int doctorID, int patientID, String date, String time) {
        this.appointmentID = appointmentID;
        this.doctorID = doctorID;
        this.patientID = patientID;
        this.date = date;
        this.time = time;
    }

    public void saveAppointment() throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("appointments.txt", true));
        writer.write(appointmentID + "," + doctorID + "," + patientID + "," + date + "," + time + "\n");
        writer.close();
    }
}

public class Main {
    public static void main(String[] args) {
        try {

            Doctor dip = new GeneralPractitioner(1, "Dr. Dip", "9 AM - 5 PM");
            Doctor dipto = new Specialist(2, "Dr. Dipto", "Cardiologist", "10 AM - 4 PM");
            Doctor arefin = new GeneralPractitioner(3, "Dr. Arefin", "8 AM - 2 PM");
            Doctor rony = new Specialist(4, "Dr. Rony", "Neurologist", "11 AM - 3 PM");
            Doctor rani = new GeneralPractitioner(5, "Dr. Rani", "12 PM - 6 PM");
            Doctor bushra = new Specialist(6, "Dr. Bushra", "Dermatologist", "9 AM - 12 PM");
            Doctor ahad = new GeneralPractitioner(7, "Dr. Ahad", "7 AM - 1 PM");
            Doctor mim = new Specialist(8, "Dr. Mim", "Pediatrician", "1 PM - 4 PM");
            Doctor jony = new GeneralPractitioner(9, "Dr. Jony", "8 AM - 5 PM");
            Doctor asma = new Specialist(10, "Dr. Asma", "Oncologist", "11 AM - 2 PM");
            Doctor rafi = new GeneralPractitioner(11, "Dr. Rafi", "9 AM - 5 PM");
            Doctor sara = new Specialist(12, "Dr. Sara", "Cardiologist", "10 AM - 4 PM");


            dip.saveDoctorInfo();
            dipto.saveDoctorInfo();
            arefin.saveDoctorInfo();
            rony.saveDoctorInfo();
            rani.saveDoctorInfo();
            bushra.saveDoctorInfo();
            ahad.saveDoctorInfo();
            mim.saveDoctorInfo();
            jony.saveDoctorInfo();
            asma.saveDoctorInfo();
            rafi.saveDoctorInfo();
            sara.saveDoctorInfo();

            dip.displayAvailability();
            dipto.displayAvailability();
            arefin.displayAvailability();
            rony.displayAvailability();
            rani.displayAvailability();
            bushra.displayAvailability();
            ahad.displayAvailability();
            mim.displayAvailability();
            jony.displayAvailability();
            asma.displayAvailability();
            rafi.displayAvailability();
            sara.displayAvailability();

            Patient patient = new Patient(101, "Jane Doe", 30);
            Appointment appointment = new Appointment(1001, dip.getDoctorID(), patient.getPatientID(), "2024-09-15", "10:00 AM");
            patient.bookAppointment(dip, appointment);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
