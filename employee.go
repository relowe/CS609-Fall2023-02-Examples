package main

type Employee struct {
    Person
    Salary float64
}

func NewEmployee(name, email, phone string, salary float64) *Employee {
    return &Employee{
        Person: Person{Name: name, Email: email, Phone: phone},
        Salary: salary,
    }
}
