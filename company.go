package main

type Company struct {
	Name      string
	Employees []*Employee
	Customers []*Customer
}

func NewCompany(name string) *Company {
	return &Company{
		Name:      name,
		Employees: []*Employee{},
		Customers: []*Customer{},
	}
}

func (c *Company) AddEmployee(employee *Employee) {
	c.Employees = append(c.Employees, employee)
}

func (c *Company) AddCustomer(customer *Customer) {
	c.Customers = append(c.Customers, customer)
}
