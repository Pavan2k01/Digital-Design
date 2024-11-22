import { Component, OnInit } from '@angular/core';
import { FakestoreProductContract } from '../../Contracts/FakestoreProductContract';

@Component({
  selector: 'app-shopper-template',
  templateUrl: './shopper-template.component.html',
  styleUrls: ['./shopper-template.component.css']
})
export class ShopperTemplateComponent implements OnInit {

  public Categories:string[] = [];
  public Products:FakestoreProductContract[] = [];
  public CartItems:FakestoreProductContract[] = [];
  public CartItemsCount:number = 0;
  public isCartVisible:boolean = false;

  public LoadCategories():void {
    fetch(`http://fakestoreapi.com/products/categories`)
    .then(response=> response.json())
    .then(data=> {
      data.unshift(`all`);
      this.Categories = data;
    })
  }
  public LoadProducts(url:string):void {
    fetch(url)
    .then(response=> response.json())
    .then(data=> {
      this.Products = data;
    })
  }
  public CategoryChanged(categoryName:string):void {
    if(categoryName == "all") {
      this.LoadProducts(`http://fakestoreapi.com/products`)
    } else{
      this.LoadProducts(`http://fakestoreapi.com/products/category/${categoryName}`)
    }
  }
  public GetCartItemsCount():void {
    this.CartItemsCount = this.CartItems.length;
  }
  public AddToCartClick(id:number):void {
    fetch(`http://fakestoreapi.com/products/${id}`)
    .then(response=> response.json())
    .then(data=> {
      this.CartItems.push(data);
      this.GetCartItemsCount();
      alert(`${data.title}\n Added to Cart`)
    })
  }
  public ToogleCart():void {
    this.isCartVisible = (this.isCartVisible==false)?true:false;
  }
  public RemoveClick(index:number):void {
    this.CartItems.splice(index, 1)
    this.GetCartItemsCount();
  }

  ngOnInit(): void {
    this.LoadCategories();
    this.LoadProducts(`http://fakestoreapi.com/products`);
    this.GetCartItemsCount();
  }
}
