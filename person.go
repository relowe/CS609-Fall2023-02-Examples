package main

type Person struct {
    Name  string
    Email string
    Phone string
}

func NewPerson(name, email, phone string) *Person {
    return &Person{
        Name:  name,
        Email: email,
        Phone: phone,
    }
}
