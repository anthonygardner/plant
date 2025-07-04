import typer


app = typer.Typer()


@app.command()
def sitl():
    print("Running in SITL mode...")


@app.command()
def hitl():
    print("Running in HITL mode...")


if __name__ == "__main__":
    app()
