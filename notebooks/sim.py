import marimo

__generated_with = "0.14.10"
app = marimo.App(width="medium")


@app.cell
def _():
    import marimo as mo
    return


@app.cell
def _():
    import numpy as np
    import pandas as pd
    import plotly.graph_objects as go
    return go, np


@app.cell
def _():
    from plant.filters import KalmanFilter
    from plant.math import Matrix, Quaternion, Vector
    return KalmanFilter, Matrix, Quaternion, Vector


@app.cell
def _(Vector):
    u = Vector(0, 1, 2)
    v = Vector(-1, 1, 1)
    v
    return u, v


@app.cell
def _(Matrix):
    m = Matrix(3, 3)
    m
    return


@app.cell
def _(KalmanFilter, u):
    kf = KalmanFilter(u)
    kf.predict()
    return


@app.cell
def _(Quaternion, np, v):
    q = Quaternion(0, v.x, v.y, v.z)
    qv = np.array([q.x, q.y, q.z])

    A = q.to_matrix()
    A
    return (qv,)


@app.cell
def _(go, np, qv):
    origin = np.array([0, 0, 0])

    fig = go.Figure()

    fig.add_trace(go.Scatter3d(
        x=[origin[0], qv[0]],
        y=[origin[1], qv[1]],
        z=[origin[2], qv[2]],
        mode='lines',
    ))

    fig.add_trace(go.Cone(
        x=[qv[0]],
        y=[qv[1]],
        z=[qv[2]],
        u=[qv[0] - origin[0]],
        v=[qv[1] - origin[1]],
        w=[qv[2] - origin[2]],
        colorscale='Blues',
        sizemode='absolute',
        sizeref=0.1,
        showscale=False,
    ))

    fig.update_layout(
        width=800,
        height=600,
        scene=dict(
            camera=dict(up=dict(x=0, y=0, z=1)),
            aspectratio=dict(x=1, y=1, z=0.75),
            aspectmode="manual",
        ),
    )

    fig
    return


@app.cell
def _():
    return


if __name__ == "__main__":
    app.run()
