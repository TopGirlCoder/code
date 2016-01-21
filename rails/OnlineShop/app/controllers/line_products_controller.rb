class LineProductsController < ApplicationController
  include CurrentCart

  before_action :set_cart, only: [:create]
  before_action :set_line_product, only: [:show, :edit, :update, :destroy]

  def index
    @line_products = LineProduct.all
  end

  def show
  end

  def new
    @line_product = LineProduct.new
  end

  def edit
  end

  def create
    product = Product.find(params[:product_id])
    @line_product = @cart.add_product(product.id)

    respond_to do |format|
      if @line_product.save
        format.html { redirect_to @line_product.cart }
        format.json { render :show, status: :created, location: @line_product }
      else
        format.html { render :new }
        format.json { render json: @line_product.errors, status: :unprocessable_entity }
      end
    end
  end

  def update
    respond_to do |format|
      if @line_product.update(line_product_params)
        format.html { redirect_to @line_product }
        format.json { render :show, status: :ok, location: @line_product }
      else
        format.html { render :edit }
        format.json { render json: @line_product.errors, status: :unprocessable_entity }
      end
    end
  end

  def destroy
    @line_product.destroy
    respond_to do |format|
      format.html { redirect_to line_products_url }
      format.json { head :no_content }
    end
  end

  private
    def set_line_product
      @line_product = LineProduct.find(params[:id])
    end

    def line_product_params
      params.require(:line_product).permit(:product_id)
    end
end
