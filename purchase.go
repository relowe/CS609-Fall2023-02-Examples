package main

type Purchase struct {
    Item string
    Qty  int
    Cost float64
}

func NewPurchase(item string, qty int, cost float64) *Purchase {
    return &Purchase{
        Item: item,
        Qty:  qty,
        Cost: cost,
    }
}

func (p *Purchase) Total() float64 {
    return float64(p.Qty) * p.Cost
}
