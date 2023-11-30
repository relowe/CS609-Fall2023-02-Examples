package main

type Customer struct {
    Person
    History []*Purchase
}

func NewCustomer(name, email, phone string) *Customer {
    return &Customer{
        Person:  Person{Name: name, Email: email, Phone: phone},
        History: []*Purchase{},
    }
}

func (c *Customer) AddPurchase(purchase *Purchase) {
    c.History = append(c.History, purchase)
}
